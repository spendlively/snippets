#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Test {
public:
    void foo() {
        cout << "foo called" << endl;
    }

    void bar(int a) {
        cout << "bar called: " << a << endl;
    }
};

int main() {

    int a = 777;
    Test test;

//    test.foo();
//    test.bar(a);

    thread th1(&Test::foo, test);
    thread th2(&Test::bar, test, a);
    thread th3([&](){
        test.foo();
        test.bar(a);
    });

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
