//
// Created by usach on 31.03.2022.
//

#ifndef DATABASE_PROJECT_DATABASE_CLASS_H
#define DATABASE_PROJECT_DATABASE_CLASS_H

#endif //DATABASE_PROJECT_DATABASE_CLASS_H

#pragma once



/**
 * Класс база данных хранит события и соответствующие им даты
 * Методы класса позволяют производить поиск, добавление и удаление событий из базы данных
 */
class DataBase {
public:
    void AddEvent(const Date& date, const string& event) {
        /**
         * Добавляет событие в базу данных
         */
        bool event_not_in_DB = true;  // метка того, что события нет в БД
        for (const auto& e : base[date]) {
            if (event == e) {
                event_not_in_DB = false;
            }
        }
        if (event_not_in_DB) {
            base[date].push_back(event);
            sort(begin(base[date]), end(base[date]));
        }
    };

    bool DeleteEvent(const Date& date, const string& event) {
        /**
         * Удаляет событие из базы данных
         */
        bool event_in_DB = false;  // метка того, что событие есть в БД
        for (const auto& e : base[date]) {
            if (event == e) {
                event_in_DB = true;
            }
        }
        if (event_in_DB) {
            vector<string> v1;
            for (auto &elem : base[date]) {
                if (elem != event) {
                    v1.push_back(elem);
                }
            }
            base[date] = v1;
            cout << "Deleted successfully" << endl;
        } else {
            cout << "Event not found" << endl;
        }
        return event_in_DB;
    };

    int DeleteDate(const Date& date) {
        /**
         * Удаляет из базы данных все события, соответствующие конкретной дате
         */
        int n = base[date].size();
        base[date].clear();
        cout << "Deleted " << to_string(n) << " events" << endl;
        return n;
    };

    void Find(const Date& date) const {
        /**
         * Производит поиск всех событий, соответствущих конкретной дате
         */
        for (const auto& item : base) {
            if (item.first == date) {
                for (const auto& event : item.second) {
                    cout << event << endl;
                }
            }
        }
    };

    void Print() const {
        /**
         * Выводит содержимое базы данных
         */
        for (const auto& item : base) {
            for (const auto& event : item.second) {
                cout << item.first << " " << event << endl;
            }
        }
    };

private:
    map<Date, vector<string>> base;
};
