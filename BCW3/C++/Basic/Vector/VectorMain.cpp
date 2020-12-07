#include <iostream>
#include "Vector.h"

int main() {
    Vector a(2, 7);
    Vector b(4, 2);
    Vector c;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    if ( a == b ) {
        std::cout << "Vector is equal" << std::endl;
    } else {
        std::cout << "Vector is not equal" << std::endl;
    }
    
    std::cout << "len: " << a.len() << std::endl;
    
    return 0;
}
