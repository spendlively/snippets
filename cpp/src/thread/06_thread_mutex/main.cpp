#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void square(char ch)
{
    //Блокировка
    mtx.lock();

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;

    //Разблокировка
    mtx.unlock();
}

/**
 * mutex - блокировка
 * lock() - заблокировать
 * unlock() - разблокировать
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
