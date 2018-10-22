#include "headers/arrays.h"

using namespace std;

int arrays() {

    //Одномерный динамический массив
    int size = 3;
    int *a = new int[size];

    cout << "Одномерный динамический массив: int *a = new int[" << size << "]; " << endl;

    for (int i = 0; i < size; ++i) {

        a[i] = rand() % 10;
        cout << "a[" << i << "] = " << a[i] << "\t";
        cout << "*(a + " << i << ") = " << *(a + i) << "\t";
        cout << "a + " << i << " = " << a + i << endl;
    }
    cout << endl;

    delete[] a;





    //Двумерный динамический массив
    int sizeB = 3;
    int **b = new int *[sizeB];

    cout << "Двумерный динамический массив: int **b = new int *[" << size << "]; " << endl;

    for (int j = 0; j < sizeB; ++j) {

        b[j] = new int[sizeB];
        for (int k = 0; k < sizeB; ++k){
            b[j][k] = rand() % 10;
            cout << "b[" << j << "][" << k << "] = " << b[j][k] << "\t";
        }
        cout << endl;

    }
    cout << endl;

    for (int j = 0; j < sizeB; ++j) {
        delete[] b[j];
    }

    delete[] b;
}
