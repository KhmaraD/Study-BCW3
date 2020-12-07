#include <iostream>

#include "Pen.h"
#include "Paper.h"

Pen::Pen(int inkCapacity) {
    this->inkAmount = inkCapacity;
    this->inkCapacity = inkCapacity;
}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    int len = message.size();
    int freeSpace = paper.getMaxSymbols() - paper.getSymbols();
    
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }
    
    if ( this->inkAmount < len ) {
        len = this->inkAmount;
    }
    
    if ( freeSpace < len ) {
        len = freeSpace;
    }
    
    paper.addContent(message.substr(0, len));
    this->inkAmount -= len;
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}
