#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    //Решение проблемы с повторяемым результатом
    srand(time(NULL));

    random_shuffle(begin(arr), end(arr));

    for(auto el : arr){
        cout << el;
    }
    cout << endl;

    return 0;
}
