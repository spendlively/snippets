#include "headers/objects.h"

using namespace std;

class MyClass {
public:
    double x;

    void show() {
        cout << "x = " << x << endl;
    }

    MyClass(double z) {
        x = z;
        cout << "1) Object with x = " << x << " has been created!\n";
    }

    MyClass() {
        x = 0;
        cout << "2) Object with x = " << x << " has been created!\n";
    }

    //Деструктор
    ~MyClass() {
        cout << "3) Object with x = " << x << " has been deleted!\n";
    }
};

int objects() {

    /////////////////////////////////
    //////////////Объект/////////////
    /////////////////////////////////

    cout << "Выделение памяти объектам:" << endl;

    MyClass *p;
    p = new MyClass;
    p->show();
    delete p;

    p = new MyClass(1);
    p->show();
    delete p;

    return 0;
}
