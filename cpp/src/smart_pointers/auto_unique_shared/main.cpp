#include <iostream>
#include <memory>

using namespace std;

/**
 * Встроенные умные указатели,
 * освобождающие память
 * после выхода из области видимости функции
 */

void autoPointerTest() {
    auto_ptr<int> autoPtr1(new int(5));
    auto_ptr<int> autoPtr2(autoPtr1);
    //После этого шага autoPtr1 потеряет связь с данными
}

void uniquePointerTest() {
    unique_ptr<int> uniquePtr1(new int(5));
//    //Передача одного unique_ptr другому запрещена
//    unique_ptr<int> uniquePtr2(uniquePtr1);

    unique_ptr<int> uniquePtr2;
    uniquePtr2 = move(uniquePtr1);
//    uniquePtr2.swap(uniquePtr1);
    //После этого шага uniquePtr1 тоже потеряет связь с данными
}

void sharedPointerTest() {
    //Несколько shared_ptr могут ссылаться
    //на одни и те же данные.
    //Реализовано с помощью счетчика ссылок
    shared_ptr<int> sharedPtr1(new int(5));
    shared_ptr<int> sharedPtr2(sharedPtr1);
}

void sharedPointerArrayTest() {

    int size = 5;
    //Важно не забыть указать <int[]>
//    int *arr = new int[size] {1,2,3,4,5};
//    shared_ptr<int[]> ptr(arr);
    shared_ptr<int[]> ptr(new int[size] {1,2,3,4,5});

    for (int i = 0; i < size; ++i) {
        cout << ptr[i] << endl;
    }
}

int main() {

    autoPointerTest();

    uniquePointerTest();

    sharedPointerTest();

    sharedPointerArrayTest();

    return 0;
}

//Чтобы удалить deprecated warning
//g++ -Wno-deprecated main.cpp -o main && ./main
