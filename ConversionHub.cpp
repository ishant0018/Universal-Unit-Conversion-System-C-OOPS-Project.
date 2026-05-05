#include "ConversionHub.h"
#include "Converters.h"   

 
ConversionHub::ConversionHub() {
    keys[0] = "length";       converters[0] = new LengthConverter();
    keys[1] = "weight";       converters[1] = new WeightConverter();
    keys[2] = "temperature";  converters[2] = new TemperatureConverter();
    keys[3] = "speed";        converters[3] = new SpeedConverter();
    keys[4] = "area";         converters[4] = new AreaConverter();
    keys[5] = "volume";       converters[5] = new VolumeConverter();
    keys[6] = "time";         converters[6] = new TimeConverter();
    keys[7] = "energy";       converters[7] = new EnergyConverter();                 //keys array stores category names
    keys[8] = "pressure";     converters[8] = new PressureConverter();        // converters array stores objects of different converter classes
    keys[9] = "data";         converters[9] = new DataConverter();          //helps the program select the correct converter based on the category.”
}                                                                         
ConversionHub::~ConversionHub() {
    for (int i = 0; i < COUNT; i++) delete converters[i];               //   using a loop to prevent memory leaks.”
}
 
ConversionResult ConversionHub::convert(const string& category,
                                         double value,
                                         const string& from,                               
                                         const string& to) const {
    int idx = findIndex(toLower(category));                                             //  converts the input category to lowercase
    if (idx == -1) {                                                                      //finds its index using findIndex().
        string msg = "Unknown category: " + category + ". Valid: ";
        for (int i = 0; i < COUNT; i++) msg += keys[i] + " ";
        throw invalid_argument(msg);
    }
    return converters[idx]->getResult(value, from, to);
}
 
void ConversionHub::listAllUnits() const {                                //displays all available units for every category
    cout << "\nAvailable Units\n";
    cout << "===============\n";
    for (int i = 0; i < COUNT; i++)
        converters[i]->listUnits();
}
 
void ConversionHub::listCategories() const {
    cout << "\nCategories: ";
    for (int i = 0; i < COUNT; i++) cout << keys[i] << "  ";
    cout << "\n";
}
 
