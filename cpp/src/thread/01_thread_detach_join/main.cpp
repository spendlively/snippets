#include <iostream>
#include <thread>
#include <chrono> //Работа со временем

using namespace std;

void thread1Func()
{
    cout << "Start thread id = " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5));
    cout << "Stop thread id = " << this_thread::get_id() << endl;
}

int main()
{

    thread th(thread1Func);

    //Идентификатор потока
    cout << "Start thread id = " << this_thread::get_id() << endl;

    //Приостановить работу потока на 3 секунды
    //Для эмуляции длительности выполняние задачи
    this_thread::sleep_for(chrono::milliseconds(3));

    cout << "Stop thread id = " << this_thread::get_id() << endl;

    //Не дожидаться завершения выполнения этого потока
//    th.detach();

    //Дожидаться завершения выполнения этого потока
    //(вызывать в том месте кода, где мы хотим дождаться
    //завершения выпролнения потока - в конце)
    //Т.е. где стоит join, в том месте основной потом и будет ждать завершения параллельного
    th.join();

    return 0; 
}

//g++ -pthread main.cpp -o main && ./main
