#include <iostream>
#include "first.h"

using namespace std;
using namespace first;

namespace first
{
    void foo()
    {
        cout << "first::foo" << endl;
    }
}

namespace second
{
    void foo()
    {
        cout << "second::foo" << endl;
    }
}

int main()
{
    first::foo();
    first::bar();
    bar();
    second::foo();

    return 0;
}

//g++ main.cpp first.cpp -o main && ./main
