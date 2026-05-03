# Universal Unit Conversion System

A C++11 unit converter supporting **10 categories** and **100+ units**.  
Uses only `iostream`, `cmath`, and `string` — no STL containers.

## Project Structure

```
unit_converter/
├── UnitEntry.h          # POD struct: unit name + conversion factor
├── ConversionResult.h   # Result struct with overloaded operator<<
├── Converter.h          # Abstract base class for all converters
├── Converters.h         # All 10 converter subclasses (header-only)
├── ConversionHub.h      # Hub that owns and dispatches to all converters
├── ConversionHub.cpp    # ConversionHub method implementations
├── Utils.h              # section(), demo(), interactiveMode() declarations
├── Utils.cpp            # Utils implementations
├── main.cpp             # Entry point: demos + optional interactive mode
└── Makefile             # Build system
```

## Build & Run

```bash
make          # compile
make run      # compile + run
make clean    # remove object files and binary
```

Or manually:
```bash
g++ -std=c++11 -Wall main.cpp ConversionHub.cpp Utils.cpp -o converter
./converter
```

## Supported Categories & Units

| Category    | Base Unit | Example Units                              |
|-------------|-----------|---------------------------------------------|
| length      | metre     | mm, cm, m, km, inch, ft, yard, mile, nmi, ly |
| weight      | kg        | mg, g, kg, tonne, lb, oz, stone, ton_us, ton_uk |
| temperature | Celsius   | C, F, K, R                                  |
| speed       | m/s       | mps, kph, mph, knot, fps, mach              |
| area        | m²        | mm2, cm2, m2, km2, inch2, ft2, acre, hectare |
| volume      | litre     | ml, L, m3, tsp, tbsp, cup, pint, gallon     |
| time        | second    | ns, ms, s, min, hr, day, week, year, century |
| energy      | Joule     | J, kJ, cal, kcal, Wh, kWh, BTU, eV         |
| pressure    | Pascal    | Pa, kPa, bar, atm, psi, torr, mmHg          |
| data        | bit       | bit, Byte, KB, MB, GB, TB, PB, Mbit, Gbit  |

## OOP Design

- `Converter` — abstract base with `convert()` and `listUnits()` pure virtuals
- 10 concrete subclasses — one per category, each owns its `UnitEntry[]` table
- `ConversionHub` — factory + dispatcher; owns converters via raw pointers
- `ConversionResult` — value-object with `operator<<` for formatted output
