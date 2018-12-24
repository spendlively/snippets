#include <iostream>
#include <functional>

using namespace std;

class Test {
public:
    int a = 301;

    void lambda() {

        auto f = [this]() {
            cout << this->a << endl;
        };
        f();
    }
};

/**
 * @return
 */
int main() {

    int a = 101;
    int b = 201;

    /**
     * Pass by value
     */
    auto f1 = [a, b]() {
        cout << a << endl;
        cout << b << endl;
        //a = 124; //переменную нельзя изменить
    };
    f1();



    /**
     * Pass by reference
     */
    auto f2 = [&a, &b]() {
        a++;
        b++; //переменную можно изменить
        cout << a << endl;
        cout << b << endl;
    };
    f2();



    /**
     * Pass all by value
     */
    auto f3 = [=]() {
        cout << a << endl;
        cout << b << endl;
    };
    f3();



    /**
     * Pass all by reference
     */
    auto f4 = [&]() {
        a++;
        b++;
        cout << a << endl;
        cout << b << endl;
    };
    f4();



    /**
     * Pass all by value with mutable
     * (параметру можно будет менять
     * как параметры переданные по значению)
     */
    auto f5 = [=]() mutable {
        a++;
        b++;
        cout << a << endl;
        cout << b << endl;
    };
    f5();
    cout << a << endl;
    cout << b << endl;




    /**
     * Захватить класс в лямбду
     */
    Test test;
    test.lambda();



    /**
     * Явное указание типа возвращаемого значения
     */
    auto f6 = [=]() -> int {
        return a;
    };
    cout << f6() << endl;

    return 0;
}
