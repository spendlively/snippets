#include <iostream>
#include <functional>

using namespace std;

void Launcher(function<void()> f)
{
    f();
}

void Launcher(function<int(int, int)> f, int a, int b)
{
    cout << f(a, b) << endl;
}

/**
 * @return
 */
int main() {

    /**
     * 1. Создание лямбды, присваивание в переменную и передача в функцию
     */
    function<void()> f;

    f = [](){
        cout << "lambda has been called!" << endl;
    };

    Launcher(f);



    /**
     * 2. Передача лямблы без создания переменной
     */
    Launcher([](){
        cout << "lambda has been called!" << endl;
    });



    /**
     * 3. Передача лямбды с параметрами
     */
//    function<int(int, int)> sum = [](int a, int b) -> int {
    function<int(int, int)> sum = [](int a, int b){
        return a + b;
    };
    Launcher(sum, 1, 2);



    /**
     * 4. Захват контекста
     */
    int value = 123;
    //Начиная с c++ 14 можно использовать auto
    auto f2 = [&value](){
        cout << value << endl;
    };
    f2();



    /**
     * 5.  Тип возвращаемого значения
     */
    auto f3 = [](){
        return 1;
    };

    auto f4 = f3();
    cout << f4 << endl;

    return 0;
}
