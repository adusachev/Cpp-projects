//
// Created by usach on 30.03.2022.
//

#ifndef MATRIX_PACKAGE_MAP_SET_VECTOR_OUT_H
#define MATRIX_PACKAGE_MAP_SET_VECTOR_OUT_H

#endif //MATRIX_PACKAGE_MAP_SET_VECTOR_OUT_H

#pragma once


#include <sstream>
#include <string>

using namespace std;


/**
 * Перегрузка операторов вывода контейнеров pair, vector, map, set
 **/
template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second> p);
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi);
template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value>& m);
template <class T>
ostream& operator<< (ostream& out, const set<T>& s);





template <typename Collection>
string Join(const Collection& c, string sep) {
    stringstream ss;
    bool first = true;  // флажок кот показывает, выводим мы первый эл-т или нет
    for (const auto& i : c) {
        if (!first) {
            ss << sep;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

// pair
template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second> p) {
    return out << '(' << p.first << ", " << p.second << ')';
}

// vector
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi) {
    return out << '[' << Join(vi, ", ") << ']';
}

// map
template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ", ") << '}';
}

//set
template <class T>
ostream& operator<< (ostream& out, const set<T>& s) {
    return out << "set(" << Join(s, ", ") << ")";
}