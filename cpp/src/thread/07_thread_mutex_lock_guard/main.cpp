#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

void square(char ch)
{
    this_thread::sleep_for(chrono::milliseconds(1000));

    {
        //Блокировка
        lock_guard<mutex> guard(mtx);

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 10; j++){
                cout << ch;
            }
            cout << endl;
        }
        cout << endl;

        //Разблокировка
        //Вызов деструктора guard при выходе из функции или из блока
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
}

/**
 * lock_guard - класс, захватывающий мьютекс в конструкторе (вызывается mtx.lock())
 * и освобождающий его в деструкторе (вызывается mtx.unlock()),
 * когда объект этого класса покидает область вилимости
 * @return
 */
int main()
{
    thread th1(square, '#');
    thread th2(square, '*');

    th1.join();
    th2.join();

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
