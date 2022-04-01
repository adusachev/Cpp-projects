
#ifndef MATRIX_PACKAGE_SOLE_CLASS_H
#define MATRIX_PACKAGE_SOLE_CLASS_H

#endif //MATRIX_PACKAGE_SOLE_CLASS_H

#pragma once


#include "map_set_vector_out.h"



double vec_norm(Matrix x);

Matrix Solve_Gauss_Seidel(Matrix& A, Matrix& f, Matrix& x0, double eps=1e-6);

vector<double> TDMA(vector<double>& a, vector<double>& b,
                    vector<double>& c, vector<double>& f);

Matrix Solve_tridiagonal(Matrix& A, Matrix& f);







double vec_norm(Matrix x) {
    /**
     Вторая норма для векторов
     **/
    double sum = 0;
    auto shape = x.GetShape();
    int n = shape[1];

    for (int i=0; i<n;i++) {
        sum += pow(x[0][i], 2);
    }

    return sqrt(sum);
}



Matrix Solve_Gauss_Seidel(Matrix& A, Matrix& f, Matrix& x0, double eps) {
    /**
    Решает СЛАУ Ax=f методом Гаусса-Зейделя
        param A: матрица системы
        param f: столбец свободных членов (класс Matrix)
        param x0: начальное приближение (класс Matrix)
        param eps: точность
        return: вектор неизвестных x (класс Matrix)
    **/
    auto shape = A.GetShape();
    int n = shape[0];

    Matrix x1 = Ones({1, n}) ;
    double inf = numeric_limits<double>::infinity();
    x1 = x1 * inf;  // для гарантированного входа в цикл

    vector<Matrix> x = {x0, x1};  // всегда храним только вектора на последних двух шагах
    Matrix x_tmp = x0;  // вспомогательная, для контроля точности и выхода из цикла

    while (vec_norm(x[1] - x_tmp) >= eps) {

        for (int i=0; i<n; i++) {
            double sum1 = 0;
            double sum2 = 0;

            for (int j=0; j<i; j++) {
                sum1 += A[i][j] * x[1][0][j];
            }
            for (int j=i+1; j<n; j++) {
                sum2 += A[i][j] * x[0][0][j];
            }

            auto new_value = (1.0 / A[i][i]) * (f[0][i] - sum1 - sum2);
            x[1].Set_elem({0, i}, new_value);
        }
        x_tmp = x[0];
        x[0] = x[1];
    }
    return x[1];
}




vector<double> TDMA(vector<double>& a, vector<double>& b,
                    vector<double>& c, vector<double>& f) {
    /**
     Алгиритм прогонки (Tridiagonal matrix algorithm)

    param a: диагональ, лежащая под главной (size = n-1)
    param b: главная диагональ (size = n)
    param c: диагональ, лежащая над главной (size = n-1)
    param f: вектор свободных членов (size = n)
    return: вектор неизвестых y
    **/
    int n = f.size();
    vector<double> alpha(n-1);
    vector<double> beta(n);

    alpha[0] = c[0] / b[0];
    beta[0] = f[0] / b[0];

    // прямая прогонка
    for (int i=1; i<n-1; i++) {
        alpha[i] = c[i] / (b[i] - a[i-1] * alpha[i-1]);
        beta[i] = (f[i] - a[i-1] * beta[i-1]) / (b[i] - a[i-1] * alpha[i-1]);

        beta[n-1] = (f[n-1] - a.back() * beta[n-2]) / (b[n-1] - a.back() * alpha.back());
    }

    // обратная прогонка
    vector<double> y(n);
    y.back() = beta.back();

    for (int i=n-2; i>=0; i--) {
        y[i] = beta[i] - alpha[i] * y[i+1];
    }
    return y;
}





Matrix Solve_tridiagonal(Matrix& A, Matrix& f) {
    /**
    Решает СЛАУ Ax=f методом прогонки
        param A: матрица системы
        param f: столбец свободных членов (класс Matrix)
        return: вектор неизвестных x (класс Matrix)
    **/
    auto shape = A.GetShape();
    int n = shape[0]; int m = shape[1];
    Assert((n == m), "Matrix is not square");

    vector<double> diag(n);
    vector<double> over_diag(n-1);
    vector<double> under_diag(n-1);

    // запись диагональных элементов в векторы
    for (int i=0; i<n; i++) {
        diag[i] = A[i][i];
        if (i != n-1) {
            over_diag[i] = A[i][i+1];
            under_diag[i] = A[i+1][i];
        }
    }
    vector<double> bias = f.GetValues()[0];

    auto ans = TDMA(under_diag, diag, over_diag, bias);

    return Matrix({ans});
}

