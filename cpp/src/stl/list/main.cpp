#include <iostream>
#include <list>

using namespace std;

template <typename T>
void PrintList(const list<T> &lst){
    for(auto i = lst.cbegin(); i != lst.cend(); i++){
        cout << *i << endl;
    }
}

int main ()
{
    /*
     * list оптимизирован для добавления элементов
     * в любом месте списка
     */

    /*
     * У list нет возможности обратиться сразу к элементу,
     * т.к. list не поддерживает оператор индексирования
     */
    list<int> myList {1, 2, 3};

    //вставить 0 3 раза удалив предыдущие значения
    //myList.assign(3, 0);

    //скопировать list
//    list<int> myList2 {10, 20, 30, 40, 50};
//    myList.assign(myList2.begin(), myList2.end());


    myList.push_back(4);
    myList.push_front(0);

    /*
     * Убалить сначала и с конца
     */
    //myList.pop_back();
    //myList.pop_front();

//    myList.sort();
//    myList.size();
    //удалить последовательно идущие дубликаты
//    myList.unique();
//    myList.reverse();
//    myList.clear();

    //вставить в указанное место
    auto it = myList.begin();
    it++;
    //не поддерживает доступ по произвольному индексу
    //чтобы сдвинуть итератор на 3 элемента
    advance(it, 3);
    myList.insert(it, 777);

    //удалить элемент с помощью итератора
    myList.erase(it);

    //удалить элемент по значению
    myList.remove(3);

    //list<int>::iterator it = myList.begin();
    //auto it = myList.begin();
    //cout << *it << endl;

//    for(auto i = myList.begin(); i != myList.end(); i++){
//        cout << *i << endl;
//    }

    PrintList(myList);

    return 0;
}

//чтобы не было warning'ов при использовании auto
//g++ -std=c++11 main.cpp -o main && ./main