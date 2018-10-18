#include "headers/simple.h"

using namespace std;

int simple() {

    cout << "Простое использование:" << endl;

    //Выделение памяти
    int *ptr = new int;
    *ptr = 5;
    cout << "*ptr = " << *ptr << endl; //5
    cout << "ptr = " << ptr << endl; //0x...



    //Освобождение памяти
    delete ptr;
    cout << "*ptr = " << *ptr << endl; //случайные данные
    cout << "ptr = " << ptr << endl; //тот же адрес



    //NULL
    //Чтобы после удаления указатель не указывал на адрес в куче
    ptr = NULL; //Или ptr = 0
//    cout << "*ptr = " << *ptr << endl; //Ошибка
    cout << "ptr = " << ptr << endl; //0

    //Проверка
    if(ptr != NULL){}



    //nullptr - Предпочтительный вариант
    ptr = nullptr;

    //Проверка
    if(ptr != nullptr){

    }

    cout << endl;
}
