#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class IAction {
public:
    virtual void Action() = 0;
};

class OneAction : public IAction {
public:
    virtual void Action() override {
        cout << "one action" << endl;
    }
};

class TwoAction : public IAction {
public:
    virtual void Action() override {
        cout << "dog action" << endl;
    }
};

class ThreeAction : public IAction {
public:
    virtual void Action() override {
        cout << "three action" << endl;
    }
};

class FourAction : public IAction {
public:
    virtual void Action() override {
        cout << "four action" << endl;
    }
};

int main() {

    IAction* arr[] = {
        new OneAction(),
        new TwoAction(),
        new ThreeAction(),
        new FourAction(),
    };

    //Решение проблемы с повторяемым результатом
    srand(time(NULL));
    random_shuffle(begin(arr), end(arr));

    for(auto el : arr){
        el->Action();
    }
    cout << endl;

    for(auto el : arr) delete el;

    return 0;
}

//g++ -fpermissive main.cpp -o main && ./main
