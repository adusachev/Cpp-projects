
#ifndef MATRIX_PACKAGE_MATRIX_OPERATIONS_H
#define MATRIX_PACKAGE_MATRIX_OPERATIONS_H

#endif //MATRIX_PACKAGE_MATRIX_OPERATIONS_H

#pragma once


#include "matrix_class.h"


Matrix Ones(const vector<int>& size);

void Assert(bool condition, string message);

Matrix operator+ (Matrix& M1, Matrix& M2);

Matrix operator- (Matrix& M1, Matrix& M2);

template <class T>
Matrix NumberMatrixMul(Matrix& M, T num);

template<class T>
Matrix operator* (T num, Matrix& M);

template<class T>
Matrix operator* (Matrix& M, T num);

Matrix operator* (Matrix& M1, Matrix& M2);

bool operator== (Matrix& M1, Matrix& M2);






Matrix Ones(const vector<int>& size) {
    /**
     param size: размер матрицы
     return: матрица заданного размера, заполненная единицами
     */
    int n = size[0];
    int m = size[1];

    vector<vector<double>> matr_values(n, vector<double>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matr_values[i][j] = 1;
        }
    }

    return Matrix(matr_values);
}


void Assert(bool condition, string message) {
    /**
     * assert с выводом сообщения
     */
    if (!condition) {
        string s = "Assertion failed: " + message;
        throw runtime_error(s);
    }
}



Matrix operator+ (Matrix& M1, Matrix& M2) {
    /**
     * Перегрузка оператора сложения
     */
    auto shape1 = M1.GetShape();
    auto shape2 = M2.GetShape();
    Assert((shape1[0] == shape2[0]) & (shape1[1] == shape2[1]),
           "matrices sizes should be same");

    auto n = shape1[0];
    auto m = shape1[1];
    vector<vector<double>> result(n, vector<double>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            result[i][j] = M1[i][j] + M2[i][j];
        }
    }
    return Matrix(result);
}




Matrix operator- (Matrix& M1, Matrix& M2) {
    /**
     * Перегрузка оператора вычитания
     */
    auto shape1 = M1.GetShape();
    auto shape2 = M2.GetShape();
    Assert((shape1[0] == shape2[0]) & (shape1[1] == shape2[1]),
           "matrices sizes should be same");

    auto n = shape1[0];
    auto m = shape1[1];
    vector<vector<double>> result(n, vector<double>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
    return Matrix(result);
}



template <class T>
Matrix NumberMatrixMul(Matrix& M, T num) {
    /**
     * Умножение матрицы на число
     */
    auto shape = M.GetShape();
    auto n = shape[0];
    auto m = shape[1];
    vector<vector<double>> result(n, vector<double>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            result[i][j] = M[i][j] * num;
        }
    }
    return Matrix(result);
}


template<class T>
Matrix operator* (T num, Matrix& M) {
    /**
     * Перегрузка оператора умножения числа на матрицу
     */
    return NumberMatrixMul(M, num);
}

template<class T>
Matrix operator* (Matrix& M, T num) {
    /**
     * Перегрузка оператора умножения матрицы на число
     */
    return NumberMatrixMul(M, num);
}



Matrix operator* (Matrix& M1, Matrix& M2) {
    /**
     * Перегрузка оператора умножения матриц
     */
    auto shape1 = M1.GetShape();
    auto shape2 = M2.GetShape();
    auto n = shape1[0];
    auto m = shape1[1];
    auto p = shape2[0];
    auto k = shape2[1];

    Assert((m == p),
           "the sizes of the matrices do not match, multiplication is impossible");

    vector<vector<double>> result(n, vector<double>(k));

    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            double sum = 0;
            for (int t=0; t<m; t++) {
                sum += M1[i][t] * M2[t][j];
            }
            result[i][j] = sum;
        }
    }
    return Matrix(result);
}


bool operator== (Matrix& M1, Matrix& M2) {
    /**
     * Перегрузка оператора сравнения матриц
     */
    auto shape1 = M1.GetShape();
    auto shape2 = M2.GetShape();
    int n = shape1[0]; int m = shape1[1];
    int p = shape2[0]; int k = shape2[1];

    Assert((n == p) & (m == k),
           "to compare matrices their sizes should be same");

    bool equal = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (M1[i][j] != M2[i][j]) {
                equal = false;
            }
        }
    }
    return equal;
}