#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * - при добавлении пары в map, ключи составляются в бинарное дерево
 * - map хранит только уникальные ключи
 * @return
 */
int main() {

    /**
     * Создания пары
     */
    pair<int, string> p(1, "test");
    cout << p.first << endl;
    cout << p.second << endl;

    map<int, string> m;
    m.insert(make_pair(1, "one"));
    m.insert(pair<int, string>(2, "two"));
    m.emplace(3, "three"); //c++ 11
    m.emplace(3, "one more three"); //не будет добавлен
    m[4] = "four";
    m.at(4) = "Four";

    //Изменение значения если есть ключ
    try {
        m.at(5) = 5;
    } catch (const std::exception &ex){
        cout << ex.what() << endl;
    }

    auto it = m.find(4);
    if (it != m.end()) {
        cout << it->first << " " << it->second << endl;
    }

    cout << m[1] << endl;

    m[1] = "One";
    cout << m[1] << endl;

    m.erase(4);
    //m.at(4) = "Four"; //ошибка



    //Multimap - может хранить дублирующиеся ключи
    //Не перегружен оператор квадратные скобки
    //Отсутствует метод at()
    multimap<int, string> mm;

    return 0;
}
