#include <iostream>
#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelAmount = 0;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const std::string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    double fuelNeed = location.distance(destination) * this->fuelConsumption;
    
    if ( fuelNeed > fuelAmount ) {
        throw OutOfFuel();
    }
    
    this->fuelAmount -= fuelNeed;
    this->location = destination;
}

void Car::drive(double x, double y) {
    drive(Point(x, y));
}

void Car::refill(double fuel) {
    double newFuel = this->fuelAmount + fuel;
    
    if ( newFuel > this->fuelCapacity ) {
        throw ToMuchFuel();
    }
    this->fuelAmount = newFuel;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    std::cout << "Car model:   " << car.getModel() << std::endl;
    std::cout << "Location:    " << car.getLocation() << std::endl;
    std::cout << "Fuel:        " << car.getFuelAmount() << '/' << car.getFuelCapacity() << std::endl;
    std::cout << "Consumption: " << car.getFuelConsumption() << std::endl;
    
    return out;
}
