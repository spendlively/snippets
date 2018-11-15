#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Test {
public:
    Test(T value) {
        this->value = value;
    }

    T getValue() {
        return this->value;
    }

    T getTypeSize() {
        return sizeof(this->value);
    }

private:
    T value;
};

int main() {

    Test<int> t(123);
    cout << t.getValue() << endl;
    cout << t.getTypeSize() << endl;

    Test<string> t2("test");
    cout << t2.getValue() << endl;
    //cout << t2.getTypeSize() << endl; //ошибка при попытке sizeof

    return 0;
}
