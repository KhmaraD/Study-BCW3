#include <iostream>
#include "Date.h"

int main() {
    Date date1;
    Date date2(29, 2, 2020);
    // Date date3(29, 2, 2019);
    // Date date4(32, 10, 2018);
    // Date date5(5, 13, 2050);
    // Date date6(12, 12, 935);
    
    std::cout << date1 << std::endl;
    std::cout << date2 << std::endl;
    // std::cout << date3 << std::endl;
    // std::cout << date4 << std::endl;
    // std::cout << date5 << std::endl;
    // std::cout << date6 << std::endl;
    
    return 0;
}
