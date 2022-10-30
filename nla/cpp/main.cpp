#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <chrono>
#include "matrix_ops.h"

Matrix manualInput(int n)
{
    Matrix A = initMatrix(n);
    std::cout << "Enter square " << n << "-dimensional matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i*n+j];
        }
    }
    return A;
}

Matrix randomInput(int n)
{
    int a, b;
    std::cout << "Define range of values (a, b) for randomly generated square " << n <<"-dimensional matrix" << std::endl;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    return generateMatrix(n, a, b);
}

int main()
{
    int n;
    std::cout << "Enter square matrix (n x n) dimension:" << std::endl << "n = ";
    std::cin >> n;

    char manual_mode;
    Matrix A;
    while (1) {
        std::cout << "Manual input of matrix? (Y/n)" << std::endl;
        std::cin >> manual_mode;
        manual_mode = std::toupper(manual_mode);
        if (manual_mode == 'Y') {
            A = manualInput(n);
            break;
        } else if (manual_mode == 'N') {
            A = randomInput(n);
            break;
        } else {
            std::cout << "Answer not recognized, try again." << std::endl;
        }
    }

    auto start = std::chrono::steady_clock::now();
    auto decomp = LUDecomposition(A, n);
    auto end = std::chrono::steady_clock::now();

    Matrix LU = std::get<0>(decomp);
    double det = std::get<1>(decomp);
    if (det == 0) {
        std::cout << "det(A) = 0, no LU decomposition exists." << std::endl;
    } else {
        if (manual_mode == 'Y') {
            printMatrix(LU, n);
        }
        std::cout << std::fixed << "det(A) = " << det << std::endl;
        std::cout << "Time spent: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
                  << " ms" << std::endl;
        std::cout << "Precision ||LU - A|| = " << precision (A, LU, n) << std::endl;
    }

    return 0;
}