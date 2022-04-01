
#include "matrix_class.h"
#include "map_set_vector_out.h"




/// конструктор по умолчанию
Matrix::Matrix() {
    values = {{0, 0, 0},
              {0, 0, 0},
              {0, 0, 0}};
    UpdateShape();
}

/// конструктор: прямое задание матрицы
Matrix::Matrix(const vector<vector<double>>& new_values) {
    values = new_values;
    UpdateShape();
}


/// получить массив значений матрицы
vector<vector<double>> Matrix::GetValues(bool print) {
    if (print) {
        cout << values << endl;
    }
    return values;
}

/// размер матрицы
vector<uint64_t> Matrix::GetShape(bool print) {
    if (print) {
        cout << "(" << shape[0] << ", " << shape[1] << ")" << endl;
    }
    return shape;
}

/// печать матрицы
void Matrix::Print() {
    for (int i=0; i<shape[0]; i++) {
        cout << values[i] << endl;
    }
}

/// перегрузка оператора индексации
vector<double> Matrix::operator[](int i) {
    return values[i];
}


/// транспонирование
Matrix Matrix::Transpose() {
    auto n = shape[0];
    auto m = shape[1];

    vector<vector<double>> result(m, vector<double>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            result[j][i] = values[i][j];
        }
    }
    return Matrix(result);
}


/// записать в элемент матрицы значение
void Matrix::Set_elem(vector<int> pos, double item) {
    int i = pos[0];
    int j = pos[1];
    values[i][j] = item;
}


void Matrix::UpdateShape() {
    shape = {values.size(), values[0].size()};
}

