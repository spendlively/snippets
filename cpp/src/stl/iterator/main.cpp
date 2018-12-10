#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v = {1,2,3,4,5};

    vector<int>::iterator it;

    it = v.begin();

    cout << *it; //1
    *it = 11;
    cout << *it; //11

    it++;
    cout << *it; //2

    it+=2;
    cout << *it << endl; //4

    //для итераторов непроизвольного доступа
    //сдвинуть индекс на 1
    advance(it, 1);
    cout << *it << endl;





    for (vector<int>::iterator i = v.begin(); i != v.end() ; ++i) {
        cout << *i;
    }
    cout << endl;

    //Константный итератор (не позволяет менять данные)
    for (vector<int>::const_iterator i = v.cbegin(); i != v.cend() ; ++i) {
        cout << *i;
    }
    cout << endl;

    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend() ; ++i) {
        cout << *i;
    }
    cout << endl;

    return 0;
}

//g++ -std=c++11 main.cpp -o main && ./main