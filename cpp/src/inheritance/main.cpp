#include <iostream>
#include <string>

using namespace std;

class Parent {
public:

    string name;

    Parent()
    {
        cout << "Parent constructor (default)" << endl;
    }

    Parent(string name)
    {
        this->name = name;
        cout << "Parent constructor (with param)" << endl;
    }

    ~Parent()
    {
        cout << "Parent destructor" << endl;
    }
};

class Child : public Parent {
public:
    Child()
    {
        cout << "Child constructor (default)" << endl;
    }

    Child(string name):Parent(name)
    {
        cout << "Child constructor (with param)" << endl;
    }

    ~Child()
    {
        cout << "Child destructor" << endl;
    }
};

int main() {

    Child c1, c2("Petr");
    c1.name = "Ivan";

    cout << c1.name << endl;
    cout << c2.name << endl;

    return 0;
}

//Модификатор доступа при наследовании
//class Child : public Parent

//public
//public -> public
//protected -> private
//private -> private

//protected
//public -> protected
//protected -> protected
//private -> private

//private
//public -> private
//protected -> private
//private -> private



