#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vector = {1, 2, 3};

    //Добавить в конец
    vector.push_back(4);

//    //Удалить 5-ый элемент
//    vector.push_back(5);
//    vector.erase (vector.begin()+4);

//    //Зарезервировать длину
//    vector.reserve(100);

//    //Очистить массив
//    vector.clear();

//    //Удалить последный элемент
//    vector.pop_back();

//    //Обрезать capacity по длине
//    vector.shrink_to_fit();

    //Возвращает 0 если массив пуст, 1 если нет
    cout << "Is empty: " << vector.empty() << endl;

    //Зарезервированная длина
    cout << "Capacity: " << vector.capacity() << endl;

//    //Изменить размер до 2
//    vector.resize(2);

    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }

    try {
        cout << vector.at(10) << endl;
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
