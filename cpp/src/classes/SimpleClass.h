#include<iostream>

using namespace std;

//Объявление класса SimpleClass:
class SimpleClass {
public:

    //Целочисленные поля класса:
    int m;
    int n;

    //Метод для вычисления суммы полей:
    int summa();

    //Метод для отображения значений полей:
    void show();

    //Метод для умножения полей на число:
    void mult(int k);
};
