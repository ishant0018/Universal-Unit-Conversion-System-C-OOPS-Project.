#include <iostream>
#include <stdexcept>
#include "Converter.h"
using std::cout;
using std::invalid_argument;

//

// 1.Length (base unit: metre)
//

class LengthConverter : public Converter {
    static const int SIZE = 10;
    unitEntry table [SIZE];
    public;
       LengthConverter() : converter("length"){
        table[0] = {"mm",0.001};
        table[1] = {"cm",0.01};
        table[2] = {"m", 1,0};
        table[3] = {"km", 1000.0};
        table[4] = {"inch"0.0254};
        table[5] = {"ft",0.3048};
        table[6] = {"yard", 0.9144};
        table[7] = {"mile", 1609.344};
        table[8] = {"nmi", 1852.0};
        table[9] = {"ly", 9.461e15};
       }
        double convert(double v, const string& f, const string& t) const override {
        return v * findFactor(f, table, SIZE) / findFactor(t, table, SIZE);
    }
    void listUnits() const override {
        cout << "  Length: mm, cm, m, km, inch, ft, yard, mile, nmi, ly\n";
    }
};
          }
    

        };
 

        //

        //2. Wieght (base unit kg)
        //

        class WeightConverter : public converter {static const int size=9;
            unitEntry table[SIZE];
            public;
            Weightconverted():
            Converter("Weight"){
                 table[0] = {"mm",0.001};
        table[0] = {"mg",0.000001};
        table[1] = {"g", 0.001};
        table[2] = {"kg", 1.0};
        table[3] = {"tonne"1000.0};
        table[4] = {"lb",0.453592};
        table[5] = {"oz", 0.0283495};
        table[6] = {"stone", 6.35029};
        table[7] = {"Ton_us", 907.185};
        table[8] = {"ton_uk", 1016.05};
            }
            double convert(double v, const string& f, const string& t) const override {
        return v * findFactor(f, table, SIZE) / findFactor(t, table, SIZE);
    }
    void listUnits() const override {
        cout << " Weight:mg,g,kg,tonne,lb,oz,stone,ton_us,ton_uk\n";
    }
};
  \\

  \\3. Temprataure (non-linear,pivot;celcius)
     //

     class TempratureConverter : public conveter{
        double toCelsius(double v, const string& u) const {
               if (u=="C") return v;
               if (u=="F") return (v- 32.0) * 5.0/9.0;
               
               if (u=="k") return v-273.15;
               if (u=="R") return (v-491.67)*5.0/9.0;
               throw invalid_argument("Unknown temprature unit:" + u +"use C,F,K or R");
        }
        double fromCelsius(double c, const string& u) const {
        if (u == "C") return c;
        if (u == "F") return c * 9.0 / 5.0 + 32.0;
        if (u == "K") return c + 273.15;
        if (u == "R") return (c + 273.15) * 9.0 / 5.0;
        throw invalid_argument("Unknown temperature unit: " + u + " use C, F, K or R");
    }
public:
   tempratureConverter();
   Converter("Temprature"){}
   double convert(double v,const string& t) const override {
      return fromcelsius(tocelsius(v,f),t);
   }
    void list units() const override {
         cout <<"Temprature:C,F,k,R\n";
         }
        };
        //

        //4. Speed (base unit: m/s)
        //

        class speedConverter : public Converter {
            static const int size = 6;
            UnitEntry table[SIZE];
            public;
            Speedconverter();
            converter("speed"){
        table[0] = {"mps",1.0};
        table[1] = {"kph", 1.0 / 3.6};
        table[2] = {"mph", 0.44704};
        table[3] = {"knot"0.514444};
        table[4] = {"fps",0.3048};
        table[5] = {"mach",340.29};
            }
             double convert(double v, const string& f, const string& t) const override {
        return v * findFactor(f, table, SIZE) / findFactor(t, table, SIZE);
    }
    void listUnits() const override {
        cout<<""Speed : mps,kph,mph,knot,fps,mach\n";
    }
    };

    //


    //5. Area (base unit :square metre)
    //
      classAreaConverter : public Converter {
      static const int Size = 10;
      UnityEntry table[SIZE];
      public;
      AreaConverter() : converter("Area){
        table[0] = {"mm2",     1e-6};
        table[1] = {"cm2",     1e-4};
        table[2] = {"m2",      1.0};
        table[3] = {"km2",     1e6};
        table[4] = {"inch2",   0.00064516};
        table[5] = {"ft2",     0.092903};
        table[6] = {"yard2",   0.836127};
        table[7] = {"acre",    4046.86};
        table[8] = {"hectare", 10000.0};
        table[9] = {"mile2",   2.59e6};
      }
       double convert(double v,connst string& f, const sting& t)const override{
        return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
       }
       void listunits() const overrride{
        cout<<" Area: mm2,cm2,m2,km2,inch2,ft2,yard2,acre2,hectare,mile2/n";
          }
        };


        //

        //6. volume (base unit :litre)
        //

        class volumeConverter():
        Conveter {
            static const int size = 14;
            unitEntry table[SIZE];
            public:
            volumeConverted();
            converter ("volume"){
                table[0]  = {"ml",     0.001};
        table[1]  = {"cl",     0.01};
        table[2]  = {"dl",     0.1};
        table[3]  = {"L",      1.0};
        table[4]  = {"m3",     1000.0};
        table[5]  = {"cm3",    0.001};
        table[6]  = {"tsp",    0.00492892};
        table[7]  = {"tbsp",   0.0147868};
        table[8]  = {"fl_oz",  0.0295735};
        table[9]  = {"cup",    0.236588};
        table[10] = {"pint",   0.473176};
        table[11] = {"quart",  0.946353};
        table[12] = {"gallon", 3.78541};
        table[13] = {"gal_uk", 4.54609};
    }
double convert(double v,const string& f, const string& t)const override {
 return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
 void listunits() const override {
     cout<<"Volume : ml,cl,dl,L.m3,cm3,tsp,tbsp,fl,oz,cup,pint
     ,quart,gallon,gal_uk\n;
       }
 }:
   //



   //7. Time (base unit second)
   //


   clas TimeConverter : public Converter("time){
        table[0]  = {"ns",      1e-9};
        table[1]  = {"us",      1e-6};
        table[2]  = {"ms",      0.001};
        table[3]  = {"s",       1.0};
        table[4]  = {"min",     60.0};
        table[5]  = {"hr",      3600.0};
        table[6]  = {"day",     86400.0};
        table[7]  = {"week",    604800.0};
        table[8]  = {"month",   2629800.0};
        table[9]  = {"year",    31557600.0};
        table[10] = {"decade",  315576000.0};
        table[11] = {"century", 3155760000.0};  
   }
   table[0]  = {"J",     1.0};
        table[1]  = {"kJ",    1000.0};
        table[2]  = {"cal",   4.184};
        table[3]  = {"kcal",  4184.0};
        table[4]  = {"Wh",    3600.0};
        table[5]  = {"kWh",   3600000.0};
        table[6]  = {"eV",    1.60218e-19};
        table[7]  = {"BTU",   1055.06};
        table[8]  = {"ft_lb", 1.35582};
        table[9]  = {"erg",   1e-7};
        table[10] = {"therm", 1.05506e8};
        double convert(double v,const string& f, const string& t)const override {
 return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
 void listunits() const override {

    cout<<"Time:ns,us,ms,s,min,hr,day,week,month,year,decade,century\n";
      }
    };
      
    //


//8. Energy (base unit; joule)
//


static const int size = 11;
unitEntry table[SIZZE];
public;
 EnergyConverted();
 Converter("Energy"){
    table[0]  = {"J",     1.0};
        table[1]  = {"kJ",    1000.0};
        table[2]  = {"cal",   4.184};
        table[3]  = {"kcal",  4184.0};
        table[4]  = {"Wh",    3600.0};
        table[5]  = {"kWh",   3600000.0};
        table[6]  = {"eV",    1.60218e-19};
        table[7]  = {"BTU",   1055.06};
        table[8]  = {"ft_lb", 1.35582};
        table[9]  = {"erg",   1e-7};
        table[10] = {"therm", 1.05506e8};
        {
            double convert(double v,const string& f, const string& t)const override {
 return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
 void listunits() const override {
    cout<<"Energy: j,kj,cal,kcal,wh,kWh,eV,BTU,ft_lb,erg,therm\n";
      }
    };

    //

     //9. Pressure (base unit: pascal)
    //


    class PressureConverter : public
    Converter {
        static const int SiZE =10;
        unitEntry table [SIZE];
        public;
         pressureConverter();
         Converter("pressure"){
             table[0] = {"Pa",   1.0};
        table[1] = {"kPa",  1000.0};
        table[2] = {"MPa",  1e6};
        table[3] = {"bar",  1e5};
        table[4] = {"mbar", 100.0};
        table[5] = {"atm",  101325.0};
        table[6] = {"psi",  6894.76};
        table[7] = {"torr", 133.322};
        table[8] = {"mmHg", 133.322};
        table[9] = {"inHg", 3386.39};
    }
    double convert(double v,const string& f, const string& t)const override {
 return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
 void listunits() const override {
    cout<<"pressure: Pa,kPa,MPa,bar,mbar,atm,psi,torr,mmHg,inHg\n";
      }
    };
      

    // 


    //10. data storage (base unit: bit)
       //



       class DataConverter : Public Converter {
        static const int size = 10;
        unitEntry table [SIZE];
        public;
        DataConverted() : Convert("Data storag"){
            table[0] = {"bit",  1.0};
        table[1] = {"Byte", 8.0};
        table[2] = {"KB",   8.0 * 1024};
        table[3] = {"MB",   8.0 * 1024 * 1024};
        table[4] = {"GB",   8.0 * 1024 * 1024 * 1024};
        table[5] = {"TB",   8.0 * 1024 * 1024 * 1024 * 1024};
        table[6] = {"PB",   8.0 * 1024 * 1024 * 1024 * 1024 * 1024};
        table[7] = {"Kbit", 1024.0};
        table[8] = {"Mbit", 1024.0 * 1024};
        table[9] = {"Gbit", 1024.0 * 1024 * 1024};
    } double convert(double v,const string& f, const string& t)const override {
 return v* findfactor(f,table,SIZE)/findfactor(t,table,SIZE);
 void listunits() const override {
    cout<<"Data Storage: bit ,Byte,KB,MB,GB,TB,PB,Kbit,Gbit\n";
 }
};























































        



    
    

















































        
        





