#include <iostream>

#include "Pen.h"
#include "Paper.h"

int main() {
    Pen pen;
    Paper paper;

    pen.write(paper, "Hello, world! Hello, world!");
    paper.show();
    
    return 0;
}
