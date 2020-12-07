#include <iostream>
#include <iomanip>

#include "Date.h"

void Date::validate(int day, int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ( year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ) {
        days[2] = 29;
    }
    
    if ( year < 1582 ) {
        throw InvalidDate("Invalid Year!");
    }
    
    if ( month < 1 || month > 12 ) {
        throw InvalidDate("Invalid Month!");
    }
    
    if ( day < 1 || day > days[month] ) {
        throw InvalidDate("Invalid Day!");
    }
}

Date::Date(int day, int month, int year) {
    this->validate(day, month, year);
    
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    std::cout << std::setfill('0') << std::setw(2) << date.getDay() << '.' << std::setw(2) << date.getMonth()
    << '.' << date.getYear();
    
    return out;
}
