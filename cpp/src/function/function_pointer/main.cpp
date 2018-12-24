#include <iostream>

using namespace std;

void foo()
{
    cout << "foo" << endl;
}

string bar()
{
    return "bar";
}

void baz(string (*barPointer)())
{
    cout << barPointer() << " from baz" << endl;
}

int main()
{
    /**
     * Указатель на функцию,
     * которая возвращает void
     * и не принимает параметров
     */
    void(*fooPointer)();

    fooPointer = foo;
    fooPointer();



    /**
     * Указатель на функцию,
     * которая возвращает строку
     * и не принимает параметров
     */
    string(*barPointer)();

    barPointer = bar;
    cout << barPointer() << endl;



    /**
     * Передача указателя на функцию в функцию
     */
    baz(barPointer);
    //или просто
    baz(bar);

    return 0;
}
