#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <deque>

using namespace std;

/**
 * queue - адаптер контейнеров, ограничивает методы (как и stack)
 * В отличие от stack с вектором очередь не работает, в отличае от стэка
 * @return
 */
int main() {
    /**
     * Методы
     * - back() - получить ссылку на последний элемент в очереди
     * - emplace() - добавить элемент
     * - empty() - пуста ли очередь
     * - front() - получить ссылку на первый элемент в очереди (не извлекая)
     * - pop() - извлечь самый первый элемент
     * - push() - добавить элемент в очередь
     * - size() - размер очереди
     * - swap() - обмен содержимым одного адаптера с другим
     */

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.back() << endl;
    cout << q.front() << endl;

    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
    cout << endl;



    //list, deque
    //vector не может быит использован!
    queue<int, list<int>> ql;

    ql.push(4);
    ql.push(5);
    ql.push(6);

    while (!ql.empty()) {
        cout << ql.front();
        ql.pop();
    }
    cout << endl;



    //Очередь с приоритетом
    //Позволяет упорядочить поступающие данные согласно приоритету
    //(сортируются от большего к меньшему)
    //Использует vector и  deque
    //Не может использовать list
    priority_queue<int> pq;
//    priority_queue<int, vector<int>> pq;

    pq.push(7);
    pq.push(8);
    pq.push(9);

    while (!pq.empty()) {
        cout << pq.top();
        pq.pop();
    }
    cout << endl;


    return 0;
}
