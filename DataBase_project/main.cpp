#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <exception>
#include<sstream>

using namespace std;

#include "date_class.h"
#include "date_operations.h"
#include "database_class.h"
#include "tests.h"




void Input() {
    /**
     * Считывание команд базы данных из стандартного ввода
     */
    DataBase baza;
    string request;

    while (getline(cin, request)) {
        stringstream cin1(request);

        string command;
        cin1 >> command;

        if (command == "Add") {
            Date date;
            cin1 >> date;
            string event;
            cin1 >> event;
            baza.AddEvent(date, event);
        }
        else if (command == "Del") {
            Date date;
            cin1 >> date;
            if (!cin1.eof()) {
                string event;
                cin1 >> event;
                baza.DeleteEvent(date, event);
            } else {
                baza.DeleteDate(date);
            }
        }
        else if (command == "Find") {
            Date date;
            cin1 >> date;
            baza.Find(date);
        }
        else if (command == "Print") {
            baza.Print();
        } else if (command != "") {
            string message = "Unknown command: " + command;
            throw runtime_error(message);
        }
    }
}




int main() {
    try {
        Input();
    } catch (exception& ex) {
        cout << ex.what();
    }


    return 0;
}
