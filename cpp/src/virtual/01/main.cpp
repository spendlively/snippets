#include <iostream>

using namespace std;

class Parent{
public:
    void one(){
        cout << "parent one" << endl;
    }
    void two(){
        cout << "parent two" << endl;
    }
    virtual void three(){
        cout << "parent three" << endl;
    }
    virtual void four(){
        cout << "parent four" << endl;
    }
    virtual void five(){
        cout << "parent five" << endl;
    }
};

class Child : public Parent{
public:
    void two(){
        cout << "child two" << endl;
    }
    void three(){
        cout << "child three" << endl;
    }
    void four() override {
        cout << "child four" << endl;
    }
};


/**
 * 1. virtual
 * - виртуальный метод нужен чтобы можно было переопределить в дочернем классе
 *
 * 2. оverride
 * - оverride - нужен для контроля сигнатуры метода при перегрузке родительского метода
 * - оverride - необязательное ключевое слово
 * - если override не указан но сигнатура верна, метод все равно будет переопределен
 * - рекоммендуется override использовать всегда
 * - нельзя указать override в методе дочернего класса, если метод базового класса не virtual
 *
 * Если не использовать ключевые слова virtual и override, то,
 * если указатель на базовый класс будет ссылаться на потомок,
 * у него вызовется метод базового класса, на не потомка.
 * Parent* p = &child;
 * p->action();
 * //вызовется метод базового класса, а не потомка
 *
 * @return
 */
int main(){

    cout << "\n============ parent.method() ============\n" ;
    Parent parent;
    parent.one();
    parent.two();
    parent.three();
    parent.four();
    parent.five();

    cout << "\n============ child.method() ============\n";
    Child child;
    child.one();
    child.two();
    child.three();
    child.four();
    child.five();

    cout << "\n============ ptr_child->method() ============\n";
    Child* ptr_child = &child;
    ptr_child->one();
    ptr_child->two();
    ptr_child->three();
    ptr_child->four();
    ptr_child->five();

    cout << "\n============ ptr_parent->method() ============\n";
    Parent* ptr_parent = &child;
    ptr_parent->one();
    ptr_parent->two();
    ptr_parent->three();
    ptr_parent->four();
    ptr_parent->five();

    return 0;
}
