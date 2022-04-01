//
// Created by usach on 31.03.2022.
//

#ifndef DATABASE_PROJECT_TESTS_H
#define DATABASE_PROJECT_TESTS_H

#endif //DATABASE_PROJECT_TESTS_H

#pragma once


void test() {
    /**
     * Пример взаимодействия с классом DataBase
     */
    DataBase baza;

    baza.AddEvent({1, 1, 1}, "event1");
    baza.AddEvent({1, 1, 1}, "event2");
    baza.AddEvent({1, 1, 1}, "event3");
    baza.AddEvent({1, 1, 1}, "event4");
    baza.AddEvent({0, 4, 10}, "birthday");
    baza.AddEvent({2017, 12, 31}, "new year");
    baza.AddEvent({2017, 12, 31}, "new year");
    baza.AddEvent({2017, 12, 31}, "old year");
    baza.Print();
    cout << endl;

    baza.DeleteEvent({1, 1, 1}, "event1");
    baza.Print();
    cout << endl;

    baza.DeleteDate({2017, 12, 31});
    baza.Print();
    cout << endl;
}

