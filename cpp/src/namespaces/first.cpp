#include <iostream>
#include "first.h"

namespace first {
    void bar() {
        std::cout << "first::bar" << std::endl;
    }
}

////или
//void first::bar() {
//    std::cout << "first::bar" << std::endl;
//}
