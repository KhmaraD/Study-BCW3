// #include <iostream>
// #include <cstdlib>
// #include "List.h"

// using namespace std;

// int main() {
//     List* list = new List;

//     cout << *list << endl;
//     cout << "push_back elements: " << endl;

//     for ( int i = 0; i < 15; i++ ) {
//         list->push_back(15*i);
//     }
//     cout << *list << endl;

//     cout << "erase elements: " << endl;
//     list->erase(3);
//     cout << *list << endl;

//     cout << "insert elements: " << endl;
//     list->insert(99, 2);
//     cout << *list << endl;

//     cout << "sorted elements: " << endl;
//     list->sort();
//     cout << *list << endl;

//     cout << "find element: " << endl;
//     list->find(12);

//     cout << "pop_back elements: " << endl;
//     list->pop_back();
//     cout << *list << endl;
//     list->pop_back();
//     list->pop_back();
//     cout << *list << endl;

//     delete list;

//     return 0;
// }

#include <iostream>
#include "List.h"

int main() {
    List* com1 = new List();
    List* com2 = new List();
    
    
    std::cout << com2->size() << std::endl;
    std::cout << com2->max_size() << std::endl;
    
    com2->push_back(5);
    com2->push_back(4);
    com2->push_back(3);
    com2->push_back(2);
    com2->push_back(1);
    com1->push_back(1);
    com1->push_back(2);
    com1->push_back(3);
    com1->push_back(4);
    com1->push_back(5);
    
    std::cout << *com1 << std::endl;
    std::cout << *com2 << std::endl;
    
    com2->erase(0);
    std::cout << "erase:     " << *com2 << std::endl;

    com2->insert(0, 3);
    std::cout << "insert:    " << *com2 << std::endl;
        
    std::cout << com2->find(2) << std::endl;
    
    com2->push_back(5);
    std::cout << "push_back: " << *com2 << std::endl;
    
    com2->pop_back();
    std::cout << "pop_back:  " << *com2 << std::endl;

    com2->sort();
    std::cout << "sort:      " << *com2 << std::endl;

    std::cout << (*com2)[1] << std::endl;

    return 0;
}