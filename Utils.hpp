#include <string>
#include "ConversionHub.h"
using std::string;
 

void section(const string& title);
 
void demo(ConversionHub& hub,             // performs a single conversion using the ConversionHub
          const string& cat,
          double val,
          const string& from,
          const string& to);

void interactiveMode(ConversionHub& hub);
