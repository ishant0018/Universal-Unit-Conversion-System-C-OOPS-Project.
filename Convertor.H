#include <string>
#include<stdexcept>
#include "UnitEntry.h"
#include "Conversionresult.h"

using std:: string;
using std :: invalid_argument;

//Abstract base class for all unit covertures.
//Each category (Length ,Weight,etc.)inherits from this.
class converter{
    protected:
    string CategoryName ;

    //throws invalid_argument if the unit is not found.

    double findFactor(const string& unit ,const Unitentry * table,int size )const{
        for (int i=0;i<size;i++)
        if (table[i].name==unit)
        return table[i].factor;
        throw invalid_argument(
            "unknown unit:"+ unit + "in category " + CategoryName);

    }
    public:
    explicit converter (const string& name) : CategoryName(name){}
    virtual ~converter(){}

    //convert value from one unit to another ( pure virtual)
    virtual double convert(double value, const string& from, const string& to ) const =0;

    virtual void listunits() const =0;
    string getCategory() const { return CategoryName; }

    // it perform conversion and warp result in a conversionresult object
    ConversionResult getResult(double value,const string& from, const string& to) const{
        double result = convert(value ,from ,to);
        return ConversionResult(result, from , to , CategoryName);
    }

    
};

