#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void Foo() {
    cout << "Foo has been called!" << endl;
}

int Sum(int a, int b) {

    int res = a + b;
    cout << "Sum has been called! Result = " << res << endl;

    return res;
}

void Launcher(function<void()> f) {
    f();
}

void CollectionLauncher(vector<function<void()>> v) {
    for (auto &el : v) {
        el();
    }
}


/**
 * - класс std::function - полиморфная обертка для функций
 * - std::function - может хранить любой вызываемый объект
 * - поведение схоже с указанием на функция но из мира ооп
 *
 * @return
 */
int main() {

    //Сохранение ссылки std::function на Foo
    function<void()> f;
    f = Foo;
    f();

    //Передача ссылки std::function в функцию Launcher
    Launcher(f);

    //Передача массива ссылок std::function в функцию CollectionLauncher
    vector<function<void()>> v = {f, f, f};
    CollectionLauncher(v);

    //Сохранение ссылки std::function на функцию с параметрами
    function<int(int, int)> s;
    s = Sum;
    s(1, 2);

    return 0;
}
