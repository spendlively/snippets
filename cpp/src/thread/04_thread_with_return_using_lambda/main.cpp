#include <iostream>
#include <thread>
#include <chrono> //Работа со временем

using namespace std;

int sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    return a + b;
}

int main()
{
    int result;

    //В конструктор передаем лямбду,
    //внутри которой присваиваем результат
    //в переменную result
    thread th([&result](){
        result = sum(1, 2);
    });

//    //Или так
//    auto lambda = [&result](){
//        result = sum(1, 2);
//    };
//    thread th(lambda);


    this_thread::sleep_for(chrono::milliseconds(500));

    th.join();

    cout << result << endl;

    return 0;
}

//g++ -pthread main.cpp -o main && ./main
