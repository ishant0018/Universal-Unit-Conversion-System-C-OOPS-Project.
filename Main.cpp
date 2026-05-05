#include <iostream>
#include <string>
#include "ConversionHub.h"
#include "Utils.h"
using std::cout;
using std::cin;
using std::string;
 
int main() {
    cout << "Universal Unit Conversion System\n";
    cout << "Libraries: iostream, cmath, string only\n";
    cout << "10 Categories, 100+ Units\n";
 
    ConversionHub hub;
    hub.listAllUnits();
 
    section("Length Conversions");
    demo(hub, "length", 1.0,   "mile",  "km");
    demo(hub, "length", 100.0, "cm",    "inch");
    demo(hub, "length", 5.0,   "ft",    "m");
 
    section("Weight Conversions");
    demo(hub, "weight", 70.0, "kg",    "lb");
    demo(hub, "weight", 16.0, "oz",    "g");
    demo(hub, "weight", 1.0,  "stone", "kg");
 
    section("Temperature Conversions");
    demo(hub, "temperature", 100.0, "C", "F");
    demo(hub, "temperature",  32.0, "F", "C");
    demo(hub, "temperature",   0.0, "C", "K");
    demo(hub, "temperature",  98.6, "F", "C");
 
    section("Speed Conversions");
    demo(hub, "speed", 1.0,   "mach", "kph");
    demo(hub, "speed", 100.0, "kph",  "mph");
 
    section("Area Conversions");
    demo(hub, "area", 1.0,   "acre",    "m2");
    demo(hub, "area", 100.0, "hectare", "acre");
 
    section("Volume Conversions");
    demo(hub, "volume", 1.0,   "gallon", "L");
    demo(hub, "volume", 500.0, "ml",     "cup");
 
    section("Time Conversions");
    demo(hub, "time", 1.0, "year",   "day");
    demo(hub, "time", 1.0, "decade", "year");
 
    section("Energy Conversions");
    demo(hub, "energy", 1.0,    "kWh", "kJ");
    demo(hub, "energy", 1000.0, "cal", "kJ");
 
    section("Pressure Conversions");
    demo(hub, "pressure", 1.0, "atm", "Pa");
    demo(hub, "pressure", 1.0, "bar", "psi");
 
    section("Data Storage Conversions");
    demo(hub, "data", 1.0, "GB",   "MB");
    demo(hub, "data", 8.0, "Byte", "bit");
 
    section("Exception Handling Demo");
    demo(hub, "length",  1.0, "parsec", "km");
    demo(hub, "unknown", 1.0, "m",      "ft");
 
    cout << "\nWant interactive mode? (yes / no): ";
    string ans; cin >> ans;
    if (ans == "yes" || ans == "y")
        interactiveMode(hub);
 
    cout << "\nProgram ended successfully.\n";
    return 0;
}
