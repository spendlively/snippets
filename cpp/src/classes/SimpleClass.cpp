#include<iostream>
#include "SimpleClass.h"

using namespace std;

//Метод для вычисления суммы полей:
int SimpleClass::summa() {
    int k = n + m;
    return k;
}

//Метод для отображения значений полей:
void SimpleClass::show() {
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
}

//Метод для умножения полей на число:
void SimpleClass::mult(int k) {
    n *= k;
    m *= k;
}
