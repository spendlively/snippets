#include <iostream>
#include <thread>
#include <chrono> //Работа со временем

using namespace std;

void doWork(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    a = a * 2;
}

int main()
{
    int a = 2;

    //Для использования ссылки нужно использовать std::ref(a)
    thread th(doWork, std::ref(a));

    this_thread::sleep_for(chrono::milliseconds(500));

    //Нельзя использовать detach, т.к. нужно дождаться результата
    th.join();

    cout << a << endl;

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
