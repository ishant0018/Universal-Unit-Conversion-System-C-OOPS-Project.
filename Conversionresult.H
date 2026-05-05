
#include <string>
#include <iostream>
#include <cmath>
using std::string;
using std::ostream;

                                     //stores the result of a unit conversion 
struct ConversionResult {
    double value;
    string fromunit;
    string toUnit;
    string category;

    ConversionResult(double v,const string& f,const string& t,const string& c)           
:value(v),fromunit(f), toUnit(t), category(c){}
                                                                //^ use parameterized constructor to initialize these values at the time of object creation
//operator overloading for formatted output

friend ostream& operator<<(ostream& os ,const ConversionResult& r){            //print the conversion result using cout instead of writing a separate print function
long long intPart =(long long)r.value;                                       //  separate the integer and fractional parts of the result
double fracpart = fabs(r.value-(double)intPart);
long long frac4 =(long long)( fracpart * 10000 + 0.5);
if (r.value<0 && intPart==0) os <<"-";                                               //handle negative values properly
os <<intPart<<".";
if (frac4 < 1000) os<<"0";
if (frac4 < 100)  os<<"0";
if (frac4 < 10)   os<<"0";
os <<frac4;
os <<" "<<r.toUnit<<"(category:"<<r.category<<",from:"<<r.fromunit<<",to:"<<r.toUnit<<")";
return os;
}
};














