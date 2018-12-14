#include <iostream>
#include <set>

using namespace std;

/**
 * Set и MultiSet
 * - реализованы на основе бинарного дерева
 * - хранят упорядоченное множество
 * - set не может хранить одинаковые числа (новый экземпляр не будет добавлен)
 * - multiset позволяет добавить несколько рдинаковых элементов
 * - нет push_back/front
 * - нет перегруженного оператора квадратных скобок
 * - нельза изменить элемент - нужно удалить и добавить новый
 *
 * @return
 */
int main()
{
    /**
     * SET
     */
    set<int> s = {9,4,8,5,6,7};
    s.insert(3); s.insert(2); s.insert(1);

    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it;
    }
    cout << endl;

    s.erase(4); //если такого элемента нет - ничего не произойдет
    for(auto &item : s){
        cout << item;
    }
    cout << endl;

    //erase и insert возвращают результат своей работы

    //Поиск элемента (возвращает итератор)
    auto iterator = s.find(5);
    cout << *iterator << endl;

    int value = 5;
    if(s.find(value) != s.end()) cout << value << endl;



    /**
     * MULTISET - может содержать дубли
     */
    multiset<int> ms = {9,9,8,8,7,7};

    //Итератор на элемент 7
    auto it1 = ms.lower_bound(7);
    cout << *it1 << endl;

    //Итератор на элемент следующий за 7 (8)
    auto it2 = ms.upper_bound(7);
    cout << *it2 << endl;

    //Диапазон чисел от upper_bound до lower_bound
    auto it3 = ms.equal_range(7);

    for(auto &item : ms) cout << item;
    cout << endl;

    return 0;
}
