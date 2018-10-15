
#include <iostream>

using namespace std;

int main() {

    int a = 123;
    int *ptr = &a;
    int &ref = a;

    cout << "a = " << a << endl;

    cout << "*ptr = " << *ptr << endl;
    cout << "ptr = " << ptr << endl;
    ptr++;
    cout << "ptr = " << ptr << endl;

    cout << "ref = " << ref << endl;
    ref++;
    cout << "ref = " << ref << endl;

    return 0;
}
