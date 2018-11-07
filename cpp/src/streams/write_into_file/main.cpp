#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "Запись в файл" << endl;

    string path = "test.txt";
    ofstream fout;

    //app - append
    fout.open(path, ofstream::app);

    if(!fout.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else{
        fout << "Данные" << endl;
    }

    fout.close();

    return 0;
}
