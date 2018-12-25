#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

void square(char ch)
{

    this_thread::sleep_for(chrono::milliseconds(1000));

//    //Сразу захватить мьютекс (как lock_guard)
//    unique_lock<mutex> ul(mtx);

    unique_lock<mutex> ul(mtx, std::defer_lock);
    ul.lock();

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;

    //Не обязательно, чтобы освободить мьютекс вручную
    ul.unlock();

    this_thread::sleep_for(chrono::milliseconds(1000));
}

/**
 * unique_lock - более гибкий чем lock_guard
 * - в момент выхода из области видимости освобождает мьютекс
 * - можно вызвать ul.unlock() в нужном месте
 * - можно захватывать мьютекс не сразу при создании объекта
 *
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

//g++ -pthread main.cpp -o main && time ./main
