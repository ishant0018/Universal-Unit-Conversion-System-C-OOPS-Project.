#include <string>
#include "ConversionHub.h"
using std::string;
 

void section(const string& title);
 
// Run a single conversion and print the result (catches exceptions)
void demo(ConversionHub& hub,             // performs a single conversion using the ConversionHub
          const string& cat,
          double val,
          const string& from,
          const string& to);

void interactiveMode(ConversionHub& hub);
