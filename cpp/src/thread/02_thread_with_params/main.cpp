#include <iostream>
#include <thread>
#include <chrono> //Работа со временем

using namespace std;

void doWork(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========== DOWORK START ID(" << this_thread::get_id() << ") ==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========== DOWORK RESULT a + b = " << a + b << " ==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========== DOWORK STOP ID(" << this_thread::get_id() << ") ==========" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main()
{
    thread th(doWork, 1, 2);

    for(int i = 0; i < 20; i++){

        cout << "Main thread ID(" << this_thread::get_id() << ") i = " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
