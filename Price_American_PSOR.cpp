//
// Created by Mark Gagarine on 2024-08-19.
//

#include <iostream>
#include "Price_American_PSOR.h"
#include <fstream>  // Include for file output

using namespace std;
using namespace Eigen;

// Function to export matrix to a CSV file
/**
 *  Function to export matrix to a CSV file used for debugging
 * @param matrix
 * @param filename
 */
void exportMatrixToCSV(const MatrixXd& matrix, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < matrix.rows(); ++i) {
            for (int j = 0; j < matrix.cols(); ++j) {
                file << matrix(i, j);
                if (j < matrix.cols() - 1) file << ",";  // Separate columns with commas
            }
            file << "\n";  // New line for next row
        }
        file.close();
        cout << "Matrix exported to " << filename << endl;
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

double payoff(double S, double K, bool type){
    if(type){
        // return call option payoff
        return max(S - K, 0.);
    }
    else{
        // return put option payoff
        return max(K - S, 0.);
    }
}

void initMatrix(MatrixXd& M, int N, double theta, double sig, double r, double dt){
    M(0,0) = 1;
    for(int row = 1; row < N; row++) {
        double a = 0.5 * theta * (pow(sig * row, 2) - (r * row));
        double b = -0.5 * (pow(sig * row, 2) + r) - 1. / dt;
        double c = 0.5 * theta * (pow(sig * row, 2) + (r * row));
        M(row, row - 1) = a;
        M(row, row) = b;
        M(row, row + 1) = c;
    }
    M(N,N) = 1;
}

void initPrev(VectorXd& d, VectorXd w, MatrixXd M1, double K, int N, int M, int t, double dt, double r){
    d(0) = K * exp(-r * (M - t) * dt);
    for(int i = 1; i < N; i++){
        d(i) = -M1(i, i - 1) * w(i - 1) - (M1(i, i) + 2./dt) * w(i) - M1(i, i + 1) * w(i + 1);
    }
    d(N) = 0;
}

void computeSOR(VectorXd& v, const MatrixXd M1, const VectorXd d, const VectorXd S_i, const int maxIter, const int N,
                const double weight, const double K, const double err, const bool type){
    int cnt = 0;
    while (cnt < maxIter){
        double error = 0.;
        double y = (d(0) - M1(0,1) * v(0)) / M1(0,0);
        y = v(0) + weight * (y - v(0));
        if(type){
            y = max(y, S_i(0) - K);
        }
        else{
            y = max(y, K - S_i(0));
        }
        error += pow(y - v(0), 2);
        v(0) = y;
        for(int i = 1; i < N; i++){
            double y = (d(i) - M1(i, i - 1) * v(i - 1) - M1(i, i + 1) * v(i + 1)) / M1(i, i);
            y = v(i) + weight * (y - v(i));
            if(type){
                y = max(y, S_i(i) - K);
            }
            else{
                y = max(y, K - S_i(i));
            }
            error += pow(y - v(i), 2);
            v(i) = y;
        }
        y = (d(N) - M1(N, N - 1) * v(N - 1)) / M1(N,N);
        y = v(N) + weight * (y - v(N));
        if(type){
            y = max(y, S_i(N) - K);
        }
        else{
            y = max(y, K - S_i(N));
        }
        error += pow(y - v(N), 2);
        v(N) = y;
        if(error < err){
            break;
        }
        cnt++;
    }
}

double interpPrice(const VectorXd v, const VectorXd S_i, const double S, const double dS){
    int jStar = S / dS;
    double price = 0.;
    price += (S - S_i(jStar)) / dS * v(jStar + 1);
    price += (S_i(jStar + 1) - S) / dS * v(jStar);
    return price;
}

double priceAmericanPSOR(const double S, const double T, const double sig, const double K, const double r, const bool type) {
    // Grid variables
    double S_min = 0.0;
    double S_max = 2. * K;
    int M = 100; // time steps
    int N = 100; // max nodes
    // Algorithm variables
    double theta = .5;
    double weight = 1.;
    int maxIter = 200;
    double err = pow(10, -4);
    double dt = T / M;
    double dS = S_max / double(N);
    // Initialize finite difference method parameters
    MatrixXd M1 = MatrixXd::Zero(N + 1, N + 1);
    initMatrix(M1, N, theta, .2, r, dt);
    // Set initial conditions
        VectorXd S_i(N + 1);
        VectorXd w(N + 1);
        VectorXd v(N + 1);
    for(int i = 0; i <= N; i++){
        S_i(i) = i * dS;
        w(i) = payoff(S_i(i), K, type);
        v(i) = payoff(S_i(i), K, type);
    }
    // Compute difference method through time
    for(int t = M - 1; t >= 0; t--){
        // Compute previous time step
        VectorXd d(N + 1);
        initPrev(d, w, M1, K, N, M, t, dt, r);
        // SOR
        computeSOR(v, M1, d, S_i, maxIter, N, weight, K, err, type);
    }
    // Interpolate option price
    double price = interpPrice(v, S_i, S, dS);
    return price;
}