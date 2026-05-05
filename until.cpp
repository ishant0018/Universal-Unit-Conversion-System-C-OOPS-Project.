#include "Utils.h"
#include <iostream>
#include <exception>
using std::cout;
using std::cin;
using std::string;
using std::exception;

void section(const string& title) {
    cout << "\n" << title << "\n";
    for (int i = 0; i < (int)title.size(); i++) cout << "-";
    cout << "\n";
}

void demo(ConversionHub& hub,
          const string& cat,
          double val,
          const string& from,
          const string& to) {
    try {
        ConversionResult r = hub.convert(cat, val, from, to);
        cout << "  " << val << " " << from << "  =>  " << r << "\n";
    } catch (const exception& e) {
        cout << "  Error: " << e.what() << "\n";
    }
}

void interactiveMode(ConversionHub& hub) {
    cout << "\nInteractive Mode  (type 'quit' to exit)\n";
    hub.listCategories();
    while (true) {
        string cat, from, to;
        double val;
        cout << "\nCategory : "; cin >> cat;
        if (cat == "quit") break;
        cout << "Value    : "; cin >> val;
        cout << "From     : "; cin >> from;
        cout << "To       : "; cin >> to;
        try {
            ConversionResult r = hub.convert(cat, val, from, to);
            cout << "\nResult: " << r << "\n";
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
}
