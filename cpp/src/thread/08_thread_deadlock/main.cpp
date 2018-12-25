#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void square(char ch)
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}

void square_shark()
{

    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(10));
    mtx2.lock();

    square('#');

    mtx1.unlock();
    mtx2.unlock();
}

void square_asterisk()
{
    //Вызывает deadlock
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(10));
    mtx1.lock();

    //Невызывает deadlock
//    mtx1.lock();
//    this_thread::sleep_for(chrono::milliseconds(10));
//    mtx2.lock();

    square('*');

    mtx2.unlock();
    mtx1.unlock();
}

/**
 * Взаимная блокировка
 * Аналогия: один музыкант взял смычок, а второй скрипку.
 *
 * Решение: нужно соблюдать порядок захвата мьютекса
 * //1 поток
 * mtx1.lock();
 * mtx2.lock();
 *
 * //2 поток
 * mtx1.lock();
 * mtx2.lock();
 *
 * @return
 */
int main()
{
    thread th1(square_shark);
    thread th2(square_asterisk);

    th1.join();
    th2.join();

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
