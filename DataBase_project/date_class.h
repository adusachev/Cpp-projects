//
// Created by usach on 31.03.2022.
//

#ifndef DATABASE_PROJECT_DATE_CLASS_H
#define DATABASE_PROJECT_DATE_CLASS_H

#endif //DATABASE_PROJECT_DATE_CLASS_H

#pragma once


/**
 Класс Дата
 Атрибуты: год, месяц, день
 Методы: позволяют получить доступ к атрибутам класса
 */
class Date {
public:
    Date(int y=0, int m=0, int d=0) {
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    };
    int GetDay() const {
        return day;
    };

private:
    int year;
    int month;
    int day;
};
