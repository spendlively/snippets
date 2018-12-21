#include <iostream>
#include <thread>
#include <chrono> //Работа со временем

using namespace std;

void doWork()
{
    cout << "Start thread id = " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5));
    cout << "Stop thread id = " << this_thread::get_id() << endl;
}

int main()
{
    thread th(doWork);

    cout << "Start thread id = " << this_thread::get_id() << endl;

    this_thread::sleep_for(chrono::milliseconds(3));

    cout << "Stop thread id = " << this_thread::get_id() << endl;

    th.join();

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
