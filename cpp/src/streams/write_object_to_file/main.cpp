#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Test{
public:
    int value = 1;
    void printValue(){
        cout << value << endl;
    }
};

int main()
{
    cout << "Запись объкта в файл" << endl;
    string path = "test.txt";

    ofstream fout;
    fout.open(path, ofstream::app);

    if(!fout.is_open()){
        cout << "Ошибка открытие файла" << endl;
    } else {
        cout << "Файл открыт для записи" << endl;

        //(char *)&point - приведение к char ссылки на объект
        Test test;

        test.value = 1;
        fout.write((char *)&test, sizeof(Test));

        test.value = 2;
        fout.write((char *)&test, sizeof(Test));
    }

    fout.close();


    ifstream fin;
    fin.open(path);

    if(!fin.is_open()){
        cout << "Ошибка открытие файла" << endl;
    } else {
        cout << "Файл открыт для чтения" << endl;

        Test t;
//        //Чтение одного объекта
//        fin.read((char *)&t, sizeof(Test));
//        t.printValue();

        //Чтение всех объектов
        while(fin.read((char *)&t, sizeof(Test))){
            t.printValue();
        }
    }

    fin.close();

    return 0;
}
