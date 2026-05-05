#include <string>
#include <stdexcept>
#include <iostream>

#include "ConversionResult.h"
using std::string;
using std::cout;
using std::invalid_argument;
                                //manage different types of unit conversion based on category and unit .

class ConversionHub {
    static const int COUNT = 10;             // maximum no. of conversion  categories . 
    
    string     keys[COUNT];          //array storing category names (like length,mass) etc
Converter* converters[COUNT]
    int findIndex(const string& cat) const {           // search for a category in keys
        for (int i = 0; i < COUNT; i++)                  
            if (keys[i] == cat) return i;
        return -1;
    }

    string toLower(const string& s) const {
        string r = s;
        for (int i = 0; i < (int)r.size(); i++)
            if (r[i] >= 'A' && r[i] <= 'Z')
                r[i] = r[i] + 32;
        return r;
    }

public:
    ConversionHub();
    ~ConversionHub();
    ConversionResult convert(const string& category,
                              double value,
                              const string& from,
                              const string& to) const;

    void listAllUnits()   const;                //display all unit available in each category
    void listCategories() const;
};
