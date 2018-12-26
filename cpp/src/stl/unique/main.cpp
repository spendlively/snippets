#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1,1,5,5,2,2,4,4,3,3};
    vector<int> vect = {1,1,5,5,2,2,4,4,3,3};

    /**
     * 1. Алгоритм unique
     * - дубли сдвигает в конец
     * - возвращает итератор, указывающий на границу
     * между нужными элементами и ненужными
     * - работает с другими контейнерами, такими как vector, list, ...
     */
    auto result = unique(begin(arr), end(arr));
    for_each(begin(arr), result, [](int a){
        cout << a;
    });
    cout << endl;

    auto result_vector = unique(begin(vect), end(vect));
    vect.erase(result_vector, vect.end());
    for_each(vect.begin(), vect.end(), [](int a){
        cout << a;
    });
    cout << endl;



    /**
     * 2. Алгоритм unique copy
     * - позволяет скопировать элементы в другой контейнер
     */
    vector<int> vect2;
    unique_copy(begin(vect), end(vect), back_inserter(vect2));
    for_each(vect2.begin(), vect2.end(), [](int a){
        cout << a;
    });
    cout << endl;

    list<int> list;
    unique_copy(begin(vect), end(vect), back_inserter(list));
    for_each(list.begin(), list.end(), [](int a){
        cout << a;
    });
    cout << endl;

    return 0;
}
