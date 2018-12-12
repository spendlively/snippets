#include <iostream>
#include <array>

using namespace std;

/**
 * Отличия от vector:
 * vector - обертка для динамического массива
 * array - обертка для статического массива
 * - необходимо сразу задать размер
 * - размер динамически не расширяется/сужается
 * - нет методов для добавления и удаления элементов
 *
 */
int main() {
    array<int, 4> arr = {0, 1, 2, 3};

//    //Заполнить значением
//    arr.fill(-1);

    //Безопасное обращение к элементу по его индексу
    cout << "arr.at(0) = " << arr.at(0) << endl;

    try {
        arr.at(4);
    } catch (const std::exception &ex) {
        cout << "arr.at(4) = " << ex.what() << endl;
    }

    //Метод size(), кот. нет в обычном массиве
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
    }
    cout << endl;

    //Arrange based циклы
    for(auto el : arr){
        cout << el;
    }
    cout << endl;

    //Доступ к первому/последнему элементу массива
    cout << "arr.front() = " << arr.front() << endl;
    cout << "arr.back() = " << arr.back() << endl;

    return 0;
}
