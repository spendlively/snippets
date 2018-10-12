#include<iostream>
#include "SimpleClass.h"

using namespace std;

int main() {mc

    //Создание объектов MyObj1 и MyObj2 класса SimpleClass:
    SimpleClass MyObj1, MyObj2;

    //Полям объектов присваиваются значения:
    MyObj1.m = 1;
    MyObj1.n = 2;
    MyObj2.m = 8;
    MyObj2.n = 9;

    //Сумма полей для разных объектов:
    cout << "Total value for MyObj1 is " << MyObj1.summa() << endl;
    cout << "Total value for MyObj2 is " << MyObj2.summa() << endl;

    //Умножение полей объектов на число:
    MyObj1.mult(3);
    MyObj2.mult(2);

    //Отображение значений полей объектов:
    MyObj1.show();
    MyObj2.show();

    return 0;
}
