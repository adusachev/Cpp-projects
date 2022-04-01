
#ifndef MATRIX_PACKAGE_MATRIX_CLASS_H
#define MATRIX_PACKAGE_MATRIX_CLASS_H

#endif //MATRIX_PACKAGE_MATRIX_CLASS_H

#pragma once


#include <iostream>
#include <sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<exception>

using namespace std;




class Matrix {
public:
    // конструктор по умолчанию
    Matrix();

    // конструктор: прямое задание матрицы
    Matrix(const vector<vector<double>>& new_values);

    // получить массив значений матрицы
    vector<vector<double>> GetValues(bool print=false);

    // размер матрицы
    vector<uint64_t> GetShape(bool print=false);

    // печать матрицы
    void Print();

    // перегрузка оператора индексации
    vector<double> operator[](int i);

    // транспонирование
    Matrix Transpose();

    // записать в элемент матрицы значение
    void Set_elem(vector<int> pos, double item);


private:
    void UpdateShape();
    vector<uint64_t> shape;
    vector<vector<double>> values;
};

