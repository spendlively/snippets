#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <vector>

using namespace std;

/**
 * Stack
 * - является не самостоятельным контейнером, а адаптером для контейнера
 * - stack позволяет ограничить vector, deque или list до функционала стэка
 * - можно посмотреть только последний элемент
 * - не поддерживает произвольный доступ и перебор элементов
 * @return
 */
int main() {

//    Функционал стэка:
//    - emplace - переносит в коллекцию без копирования (быстрее)
//    - empty - возвращает false/true
//    - push - переносит в коллекцию копию объекта
//    - size - кол-во эл-тов
//    - swap
//    - pop - удаляет последний элемент
//    - top - возвращяет последний элемент

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;



    //list, vector, deque
    stack<int, list<int>> sl;
//    stack<int, vector<int>> sl;
//    stack<int, deque<int>> sl;

    sl.push(4);
    sl.push(5);
    sl.push(6);

    while (!sl.empty()) {
        cout << sl.top();
        sl.pop();
    }
    cout << endl;

    return 0;
}
