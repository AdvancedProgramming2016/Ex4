
#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H


#include "TaxiCenter.h"
#include "Grid.h"
#include "VehicleFactory.h"
#include "StringParser.h"
#include "Clock.h"

class BaseParser;

class Trip;

class TaxiCenter;

class clock;

class MainFlow {

private:

    TaxiCenter *taxiCenter;
    Grid       *map;

public:

    /*
     * Creates a map with obstacles.
     */
    void createMap(Grid *grid);

    /*
     * Creates a taxi center.
     */
    void createTaxiCenter(Point *location);

    /*
     * Creates a new driver.
     */
    void createDriver(Driver *driver);

    /*
     * Creates a new vehicle.
     */
    void createVehicle(Vehicle *vehicle);

    /*
     * Create a new trip.
     */
    void createTrip(Trip *trip);

    /*
     * Returns the taxi center.
     */
    TaxiCenter *getTaxiCenter() const;

    /*
     * Returns the map.
     */
    Grid *getMap() const;

    /*
     * Exits the taxiCenter system by deleting all the instances and exiting.
     */
    void exitSystem();

    /*
     * Cleans the map for the next iteration.
     */
    void cleanGrid();

};


#endif //EX2_MAINFLOW_H
