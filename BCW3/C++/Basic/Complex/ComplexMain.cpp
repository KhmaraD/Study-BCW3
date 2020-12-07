#include <iostream>
#include "Complex.h"

int main() {
    Complex a(3, 7);
    Complex b(4, 2);
    Complex c;
    
    std::cout << "a: " << a; /* вывод без новой строки так как в operator<< есть ::endl*/
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    if ( a == b ) {
        std::cout << a << " is equal to " << b << std::endl;
    } else {
        std::cout << a << " is not equal to " << b << std::endl;
    }
    
    return 0;
}
