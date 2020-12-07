#include <iostream>
#include "Car.h"

int main() {
    Point point(1, 1);
    Point point2(2, 4);
    Car car1;
    Car car2(50, 0.5, point, "Renault");
    
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;
    
    car1.refill(30);
    car2.refill(40);
    
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;
    
    car1.drive(3, 1);
    car2.drive(point2);
    
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;
    
    return 0;
}
