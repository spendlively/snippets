#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

recursive_mutex rmtx;

void foo()
{
    rmtx.lock();
    rmtx.lock();
    rmtx.lock();

    cout << "foo" << endl;

    rmtx.unlock();
    rmtx.unlock();
    rmtx.unlock();
}

void recursive_foo(int number)
{
    rmtx.lock();

    cout << number;
    if(number <= 1){
        cout << endl;

        //Последнее освобождение мьютекса
        rmtx.unlock();
        return;
    }

    number--;
    recursive_foo(number);

    rmtx.unlock();
    return;
}

/**
 *  - рекурсивный мьютекс может захватываться нескольно раз подряд.
 *  - разблокироваться рекурсивный мьютекс должен столько же раз,
 *  сколько раз он был захвачен.
 *
 * @return
 */
int main()
{
    thread th1(foo);
    th1.join();

    thread th2(recursive_foo, 10);
    th2.join();

    thread th3(recursive_foo, 10);
    th3.join();

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
