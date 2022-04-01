
#ifndef MATRIX_PACKAGE_TESTS_SOLE_H
#define MATRIX_PACKAGE_TESTS_SOLE_H

#endif //MATRIX_PACKAGE_TESTS_SOLE_H

#pragma once



void AssertClose(Matrix& M1, Matrix& M2, string message, double precision=1e-6);

void PrintTestResult(Matrix& algorithm_ans, Matrix& true_ans);

void tests_Gauss_Seidel(bool verbose);

void tests_TDMA(bool verbose);





void AssertClose(Matrix& M1, Matrix& M2, string message, double precision) {
    /**
     Проверка что все значения двух матриц совпадают с некоторой точностью

     param M1, M2: сравнимаемые матрицы
     param message: сообщение для вывода в случае несовпадения
     param precision: точность совпадения
     */

     auto shape1 = M1.GetShape();
     auto shape2 = M2.GetShape();

     int n = shape1[0]; int m = shape1[1];
     int p = shape2[0]; int k = shape2[1];
     Assert(((n == p) & (m == k)),
             "to compare matrices their sizes should be same");

     bool close = true;
     for (int i=0; i<n; i++) {
         for (int j=0; j<m; j++) {
             double difference = abs(M1[i][j] - M2[i][j]);
             if (difference > precision) {
                 close = false;
             }
         }
     }
     Assert(close, message);
}


void PrintTestResult(Matrix& algorithm_ans, Matrix& true_ans) {
    /**
     * Вывод истинного решения СЛАУ и решения, полученного алгоритмом
     */
    cout << "precise solution:" << endl;
    true_ans.Print();
    cout << "numerical solution:" << endl;
    algorithm_ans.Print();
    cout << endl;
}



void tests_TDMA(bool verbose=false) {
    /**
     * Тесты для метода прогонки
     */

    if (verbose){
        cout << "TDMA tests results:" << endl;
    }

    {
        Matrix A({{6, 2, 0},
                  {3, 5, 1},
                  {0, 3, 8}});

        Matrix f({{10, 16, 30}});

        Matrix x = Solve_tridiagonal(A, f);

        Matrix ans({{1, 2, 3}});

        AssertClose(x, ans, "wrong TDMA test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }

    {
        Matrix A({{10, 2, 0, 0},
                            {3, 10, 4, 0},
                            {0, 1, 7, 5},
                            {0, 0, 3, 4}});

        Matrix f({{3, 4, 5, 6}});

        Matrix x = Solve_tridiagonal(A, f);

        Matrix ans({{0.14877589, 0.75612053, -1.00188324, 2.25141243}});

        AssertClose(x, ans, "wrong TDMA test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }

    {
        Matrix A({{-2, 1, 0, 0},
                            {1, -2, 1, 0},
                            {0, 1, -2, 1},
                            {0, 0, 1, -2}});

        Matrix f({{0.04, 0.04, 0.04, 0.04}});

        Matrix x = Solve_tridiagonal(A, f);

        Matrix ans({{-0.08, -0.12, -0.12, -0.08}});

        AssertClose(x, ans, "wrong TDMA test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }

    {
        Matrix A({{2, 3, 0, 0},
                            {6, 3, 9, 0},
                            {0, 2, 5, 2},
                            {0, 0, 4, 3}});

        Matrix f({{21, 69, 34, 22}});

        Matrix x = Solve_tridiagonal(A, f);

        Matrix ans({{3, 5, 4, 2}});

        AssertClose(x, ans, "wrong TDMA test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }
}




void tests_Gauss_Seidel(bool verbose=false) {
    /**
     * Тесты для метода Гаусса-Зейделя
     */
    if (verbose){
        cout << "Gauss-Seidel tests results:" << endl;
    }

    {
        Matrix A({{2, 1},
                            {1, 4}});

        Matrix f({{1, 1}});
        Matrix x0({{0, 0}});

        Matrix x = Solve_Gauss_Seidel(A, f, x0);

        Matrix ans({{3./7., 1./7.}});

        AssertClose(x, ans, "wrong Gauss-Seidel test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }

    {
        Matrix A({{4, 2, -1},
                            {2, 4, 1},
                            {-1, 1, 3}});

        Matrix f({{1, 1, 1}});
        Matrix x0({{0, 0, 0}});

        Matrix x = Solve_Gauss_Seidel(A, f, x0);

        Matrix ans({{5./12., -1./12., 1./2.}});

        AssertClose(x, ans, "wrong Gauss-Seidel test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }

    {
        Matrix A({{10, -1, 2, 0},
                            {-1, 11, -1, 3},
                            {2, -1, 10, -1},
                            {0, 3, -1, 8}});

        Matrix f({{6, 25, -11, 15}});
        Matrix x0({{0, 0, 0, 0}});

        Matrix x = Solve_Gauss_Seidel(A, f, x0);

        Matrix ans({{1, 2, -1, 1}});

        AssertClose(x, ans, "wrong Gauss-Seidel test result");

        if (verbose) {
            PrintTestResult(x, ans);
        }
    }
}
