#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "Чтение из файла" << endl;

    string path = "test.txt";
    ifstream fin;

    //app - append
    fin.open(path, ofstream::app);

    if(!fin.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else{

//        //Посимвольное чтение всего файла
//        char ch;
//        while(fin.get(ch)){
//            cout << ch;
//        }

//        //Чтение всего файла пословно
//        //fin >> str - считывает до первого пробела
//        string str;
//        while(!fin.eof()){
//            str = "";
//            fin >> str;
//            cout << str << endl;
//        }

        //Построчное чтение всего файла
        string str;
        while(!fin.eof()){
            str = "";
            getline(fin, str);
            cout << str << endl;
        }
    }

    fin.close();

    return 0;
}
