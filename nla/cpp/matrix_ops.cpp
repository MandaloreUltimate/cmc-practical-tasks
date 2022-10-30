#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <cstring>
#include <cmath>

#include "matrix_ops.h"

Matrix initMatrix(int n)
{
    double *A = new double[n * n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i*n+j] = 0.0;
        }
    }
    return A;
}

Matrix generateMatrix(int n, int a, int b, int seed)
{
    srand(seed);
    double *mat = new double[n * n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i*n+j] = a + (rand() % static_cast<int>(b - a + 1));
        }
    }
    return mat;
}

void printMatrix(Matrix A, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) {
                std::cout << " ";
            }
            std::cout << std::fixed << std::setiosflags(std::ios::left) << std::setw(6)
                      << std::setfill(' ') << std::setprecision(2) << A[i*n+j];
        }
        std::cout << std::endl;
    }
}

std::tuple<Matrix, double> LUDecomposition(Matrix A, int n)
{
    Matrix LU = initMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += LU[i*n+k] * LU[k * n + j];
            }
            LU[i*n+j] = (A[i*n+j] - sum);
        }

        for (int j = i + 1; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += LU[j * n + k] * LU[k * n + i];
            }
            LU[j * n + i] = (A[j * n + i] - sum) / LU[i*n+i];
        }
    }
    double det = 1;
    for (int i = 0; i < n; ++i) {
        det *= LU[i*n+i];
    }
    return std::make_tuple(LU, det);
}

Matrix multiplyMatrix(Matrix A, Matrix B, int n)
{
    Matrix AB = initMatrix(n);
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                AB[i+n*j] += A[k*n+i] * B[j*n+k];
	    }
	}
    }
    return AB;
}

double precision(Matrix A, Matrix LU, int n)
{
    Matrix L = initMatrix(n);
    Matrix U = initMatrix(n);
    Matrix A_PREC = initMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            L[i*n+j] = LU[i*n+j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            U[i*n+j] = LU[i*n+j];
        }
        U[i*n+i] = 1;
    }

    Matrix A_LU = multiplyMatrix(L, U, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A_PREC[i*n+j] = A[i*n+j] - A_LU[i*n+j];
        }
    }

    double norm = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            norm += A_PREC[i*n+j] * A_PREC[i*n+j];
        }
    }
    return std::sqrt(norm);
}
