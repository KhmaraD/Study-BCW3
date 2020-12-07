#include <iostream>
#include <cmath>

#include "Complex.h"

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex() {}
        
double Complex::getReal() const {
    return this->real;
}
double Complex::getImaginary() const {
    return this->imaginary;
}
        
bool Complex::operator==(const Complex& other) const {
    return other.real == this->real && other.imaginary == this->imaginary;
}
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}
void Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
}
void Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}
Complex Complex::operator+(const Complex& other) const {
    Complex result = *this;
    result.real += other.real;
    result.imaginary += other.imaginary;
    return result;
}
Complex Complex::operator-(const Complex& other) const {
    Complex result = *this;
    result.real -= other.real;
    result.imaginary -= other.imaginary;
    return result;
}
Complex Complex::operator*(const Complex& other) const {
    Complex result;
    result.real = this->real * other.real - this->imaginary * other.imaginary;
    result.imaginary = this->real * other.imaginary + this->imaginary * other.real;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if ( complex.getImaginary() < 0 ) {
        return std::cout << complex.getReal() << complex.getImaginary() << std::endl;
    } else {
        return std::cout << complex.getReal() << '+' << complex.getImaginary() << std::endl;
    }
}
