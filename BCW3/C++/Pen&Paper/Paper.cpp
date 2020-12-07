#include <iostream>

#include "Paper.h"
#include "Pen.h"

Paper::Paper(int maxSymbols) {
    this->maxSymbols = maxSymbols;
    this->symbols = 0;
    this->content = "";
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    int freeSpace = this->maxSymbols - this->symbols;
    
    if ( this->symbols == this->maxSymbols ) {
        throw OutOfSpace();
    }
    
    this->content += message.substr(0, freeSpace);
    
    this->symbols += this->content.size();
}

void Paper::show() const {
    std::cout << this->content << std::endl;
}
