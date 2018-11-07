#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    string path = "test.txt";
    string buf;

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if(!fs.is_open()){
        cout << "Ошибка" << endl;
        return 1;
    }

//    buf = "test";
//    fs << buf;

    while(!fs.eof()){
        buf = "";
        fs >> buf;
        cout << buf;
    }

    fs.close();

    return 0;
}
