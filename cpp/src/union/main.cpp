#include <iostream>

using namespace std;

/**
 * - позволяет хранить различные переменные в общей области памяти
 * - хранит значение только одной переменной, в других будет мусор
 * - память выделяется в размере самого большого используемого типа
 * @return
 */

union MyUnion {
    short int a;
    int b;
    float c;
};

int main() {

    MyUnion u;

    u.a = 5;
    u.b = 40000;
    u.c = 43.54;

    cout << u.a << endl; //мусор
    cout << u.b << endl; //мусор
    cout << u.c << endl; //43.54

    return 0;
}
