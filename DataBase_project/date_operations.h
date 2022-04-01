//
// Created by usach on 31.03.2022.
//

#ifndef DATABASE_PROJECT_DATE_OPERATIONS_H
#define DATABASE_PROJECT_DATE_OPERATIONS_H

#endif //DATABASE_PROJECT_DATE_OPERATIONS_H

#pragma once


/**
 * Перегрузка операторов сравнения, ввода и вывода для объектов класса Date
 */
bool operator==(const Date& left, const Date& right);

bool operator<(const Date& left, const Date& right);

ostream& operator<<(ostream& stream, const Date& date);

stringstream& operator>>(stringstream& stream1, Date& date);






bool operator==(const Date& left, const Date& right) {
    return (left.GetYear() == right.GetYear() &&
            left.GetMonth() == right.GetMonth() &&
            left.GetDay() == right.GetDay());
}

bool operator<(const Date& left, const Date& right) {
    if (left.GetYear() == right.GetYear()) {
        if (left.GetMonth() == right.GetMonth()) {
            return (left.GetDay() < right.GetDay());
        }
        return (left.GetMonth() < right.GetMonth());
    }
    return (left.GetYear() < right.GetYear());
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-'
           << setw(2) << date.GetMonth() << '-'
           << setw(2) << date.GetDay();
    return stream;
}

stringstream& operator>>(stringstream& stream1, Date& date) {
    int y, m, d;
    char sep1, sep2;
    bool wrong_sep = false;

    // чтение потока ввода
    string line;
    stream1.ignore(1);
    getline(stream1, line, ' ');
    stringstream stream(line);

    // ввод года
    stream >> y;
    stream >> sep1;
    if (sep1 != '-') {
        wrong_sep = true;
    }
    // ввод месяца
    stream >> m;
    stream >> sep2;
    if (sep2 != '-') {
        wrong_sep = true;
    }
    // ввод дня
    stream >> d;

    // обработка случаев некорректного ввода
    if (!stream || wrong_sep || !stream.eof()) {
        string message = "Wrong date format: " + line;
        throw runtime_error(message);
    }
    if (m < 1 || m > 12) {
        string message = "Month value is invalid: " + to_string(m);
        throw invalid_argument(message);
    }
    if (d < 1 || d > 31) {
        string message = "Day value is invalid: " + to_string(d);
        throw invalid_argument(message);
    }

    Date date1(y, m, d);
    date = date1;

    return stream;
}