#include <iostream>

#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) {
    this->amount = 0;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun() {}

int Gun::getAmount() const {
    return this->amount;
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this->isReady;
}

const std::string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return this->totalShots;
}

void Gun::prepare() {
    isReady = !isReady;
}

void Gun::reload() {
    amount = capacity;
}

void Gun::shoot() {
   if ( !ready() ) {
       throw NotReady();
   }
   if ( this->amount == 0 ) {
       throw OutOfRounds();
   }
   this->amount -= 1;
   this->totalShots += 1;
   std::cout << "Bang!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    std::cout << "Gun model:   " << gun.getModel() << std::endl;
    std::cout << "Capacity:    " << gun.getCapacity() << std::endl;
    std::cout << "Amount:      " << gun.getAmount() << std::endl;
    std::cout << "Total Shots: " << gun.getTotalShots() << std::endl;
    std::cout << "Ready:       ";
    if ( gun.ready() ) {
        std::cout << "ready" << std::endl;
    } else {
        std::cout << "not ready" << std::endl;
    }
    
    return out;
}
