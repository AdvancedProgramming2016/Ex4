
#include "Taxi.h"

Taxi::Taxi(Driver *driver, Vehicle *vehicle, const Point &currentPosition)
        : driver(
        driver), vehicle(vehicle), currentPosition(currentPosition), trip(0) {
}

Taxi::~Taxi() {
    delete trip;
}

Driver *Taxi::getDriver() const {
    return driver;
}

void Taxi::setDriver(Driver *driver) {
    Taxi::driver = driver;
}

Vehicle *Taxi::getVehicle() const {
    return vehicle;
}

void Taxi::setVehicle(Vehicle *vehicle) {
    Taxi::vehicle = vehicle;
}

const Point &Taxi::getCurrentPosition() const {
    return currentPosition;
}

void Taxi::setCurrentPosition(const Point &currentPosition) {
    Taxi::currentPosition = currentPosition;
}

Trip *Taxi::getTrip() const {
    return trip;
}

void Taxi::setTrip(Trip *trip) {
    Taxi::trip = trip;
}

const std::vector<Passenger> &Taxi::getPassengers() const {
    return passengers;
}

void Taxi::setPassengers(const std::vector<Passenger> &passengers) {
    Taxi::passengers = passengers;
}

void Taxi::updateSatisfaction() {

    unsigned satisfation    = 0;
    unsigned numOfCustomers = 0;
    unsigned newAverage     = 0;

    for (int i = 0; i < passengers.size(); ++i) {

        satisfation    = driver->getAvgSatisfaction();
        numOfCustomers = driver->getCounterOfCustomers();
        newAverage     = satisfation + ((passengers.at(i).generateSatisfaction()
                                         - satisfation) / numOfCustomers);
        driver->setAvgSatisfaction(newAverage);
    }
}

void Taxi::endTrip() {

    this->updateSatisfaction();
    delete trip;
    trip = 0;
}

int Taxi::registerObserver(IObserver *observer) {

    unsigned initSize = observers.size();

    observers.push_back(observer);

    if (initSize + 1 == observers.size()) {
        return 1;
    }

    return 0;

}

int Taxi::unregisterObserver(IObserver *observer) {

    for (int i = 0; i < observers.size(); ++i) {


        if (observers[i] == observer) {
            observers.erase(observers.begin() + i);
            return 1;
        }
    }

    return 0;
}

void Taxi::notifyObservers() {

    for (int i = 0; i < observers.size(); ++i) {
        observers[i]->update(this);
    }
}

const std::vector<IObserver *> &Taxi::getObservers() const {
    return observers;
}



