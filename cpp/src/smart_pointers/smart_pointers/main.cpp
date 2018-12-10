#include <iostream>

using namespace std;

/**
 * Пример создания умного указателя,
 * для автоматического освобождения динамической памяти
 * веделенной в куче, при выходе из области видимости функции
 */

template<typename T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;

        cout << "2. Constructor" << endl;
    }

    ~SmartPointer() {

        /**
         * При выходе из области видимости
         * память будет автоматически освобождена
         */
        delete ptr;

        cout << "3. Destructor" << endl;
    }

    /**
     * Перегружаем оператор *,
     * чтобы он возвращал ссылку на данные,
     * чтобы данные можно было изменить,
     * а не получить новую копию данных
     * @return
     */
    T &operator*() {
        return *ptr;
    }

private:
    T *ptr;
};

void test() {

    /**
     * Оператор new возвращает адрес в памяти
     */
    SmartPointer<int> pointer = new int(5);

    *pointer = 10;

    cout << "*pointer = " << *pointer << endl;
}

int main() {

    cout << "1. Start" << endl;

    test();

    cout << "4. End" << endl;

    return 0;
}
