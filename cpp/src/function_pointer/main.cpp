#include <iostream>

using namespace std;

void foo1()
{
    cout << "foo1" << endl;
}

string foo2()
{
    return "foo2";
}

int main()
{
    /**
     * Указатель на функцию,
     * которая возвращает void
     * и не принимает параметров
     */
    void(*foo1Pointer)();

    foo1Pointer = foo1;
    foo1Pointer();



    /**
     * Указатель на функцию,
     * которая возвращает строку
     * и не принимает параметров
     */
    string(*foo2Pointer)();

    foo2Pointer = foo2;
    cout << foo2Pointer() << endl;

    return 0;
}
