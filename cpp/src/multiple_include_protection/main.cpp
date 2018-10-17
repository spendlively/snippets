#include <iostream>
#include "one.h"
#include "two.h"

int main() {

    std::cout << "Main" << std::endl;

    one();
    two();

    return 0;
}

// g++ main.cpp one.cpp two.cpp -o test