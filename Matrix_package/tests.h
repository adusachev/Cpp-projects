
#ifndef MATRIX_PACKAGE_TESTTS_H
#define MATRIX_PACKAGE_TESTTS_H

#endif //MATRIX_PACKAGE_TESTTS_H

#pragma once

#include "matrix_class.h"
#include "matrix_operations.h"


template <class T, class U>
void AssertEqual(T& t, U& u, string message);

void Test_Sum();

void Test_Matrix_Num_Mult();

void Test_Matrix_Mult();

void Test_Transpose();






template <class T, class U>
void AssertEqual(T& t, U& u, string message) {
    if (!(t == u)) {
        ostringstream os;
        os << "Assertion failed: " << message;
        throw runtime_error(os.str());
    }
}


void Test_Sum() {
    // тест сложение матриц
    {
        Matrix M1({{2, 3},
                   {3, 4}});
        Matrix M2({{6, 7},
                   {8, 9}});
        Matrix M3 = M1 + M2;

        Matrix ans = Matrix({{8,  10},
                             {11, 13}});

        AssertEqual(M3, ans, "wrong sum result");
    }

    {
        // несовпадающие размеры
        Matrix M1({{1, 2},
                   {3, 4}});
        Matrix M2({{1, 2, 3},
                   {4, 5, 6}});
        try {
            auto M3 = M1 + M2;
        } catch(runtime_error& e){}
    }
}



void Test_Matrix_Num_Mult() {
    // тест умножение матрицы на число
    {
        Matrix M({{1, 2},
                  {3, 4}});
        double q = 2.0;
        Matrix M1 = M * q;
        Matrix ans({{2, 4},
                    {6, 8}});
    AssertEqual(M1, ans, "wrong matrix num multiplication result");
    }

    {
        Matrix M({{1, 2},
                  {3, 4}});
        double q = 2.0;
        Matrix M1 = q * M;
        Matrix ans({{2, 4},
                    {6, 8}});
        AssertEqual(M1, ans, "wrong matrix num multiplication result");
    }
}



void Test_Matrix_Mult() {
    // тест умножение матриц
    {
        Matrix M1({{1, 0},
                   {0, 1}});
        Matrix M2({{1, 2},
                   {3, 4}});
        auto M3 = M1 * M2;

        Matrix ans({{1, 2},
                    {3, 4}});
        AssertEqual(M3, ans, "wrong matrix multiplication result");
    }

    {
        Matrix M1({{4, 7},
                  {2, 5},
                  {1, 8}});
        Matrix M2({{4},
                   {3}});
        auto M3 = M1 * M2;

        Matrix ans({{37},
                            {23},
                            {28}});
        AssertEqual(M3, ans, "wrong matrix multiplication result");
    }

    {
        Matrix M1({{1, 0},
                   {2, 1},
                   {-1, 1}});
        Matrix M2({{1, 2, 0},
                   {0, -1, 1}});
        auto M3 = M1 * M2;

        Matrix ans({{1, 2, 0},
                            {2, 3, 1},
                            {-1, -3, 1}});
        AssertEqual(M3, ans, "wrong matrix multiplication result");
    }

    {
        Matrix M1({{1, 2, 3}});
        Matrix M2({{2},
                            {5},
                            {0}});
        auto M3 = M1 * M2;
        double ans = 12;
        AssertEqual(M3[0][0], ans, "wrong matrix multiplication result");
    }


    {
        // несовпадающие размеры
        Matrix M1({{1, 0},
                   {0, 1}});
        Matrix M2({{1, 2}});

        try {
            auto M3 = M1 * M2;
        } catch(runtime_error& e) {
//            cout << "error catched: " << e.what() << endl;
        }
    }
}



void Test_Transpose() {
    // тест транспонирование матрицы
    {
        Matrix M({{0, 2},
                  {3, 7},
                  {5, 6}});
        auto M1 = M.Transpose();

        Matrix ans({{0, 3, 5},
                            {2, 7, 6}});
        AssertEqual(M1, ans, "wrong matrix transpose result");
    }

    {
        Matrix M({{1, 2},
                            {3, 4}});
        auto M1 = M.Transpose();

        Matrix ans({{1, 3},
                            {2, 4}});
        AssertEqual(M1, ans, "wrong matrix transpose result");
    }

    {
        Matrix M({{1, 2, 3, 4}});
        auto M1 = M.Transpose();

        Matrix ans({{1},
                            {2},
                            {3},
                            {4}});
        AssertEqual(M1, ans, "wrong matrix transpose result");
    }

    {
        Matrix M({{1},
                            {3},
                            {4}});
        auto M1 = M.Transpose();

        Matrix ans({{1, 3, 4}});
        AssertEqual(M1, ans, "wrong matrix transpose result");
    }
}
