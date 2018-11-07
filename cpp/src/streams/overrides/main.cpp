#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Test {
public:
    int x = 1;
    int y = 1;

//Если нужен доступ к private полям
//friend ostream &operator<<(ostream &os, const Test &test);
//friend istream &operator>>(istream &is, Test &test);
};

ostream &operator<<(ostream &os, const Test &test) {
    os << test.x << " " << test.y << endl;
    return os;
}

istream &operator>>(istream &is, Test &test) {
    is >> test.x >> test.y;
    return is;
}

int main() {

//    //Ввод/вывод с консоли
//    Test t;
//    cin >> t;
//    cout << t;



    //Файловый ввод/вывод
    fstream fs;
    fs.open("test.txt", fstream::in | fstream::out | fstream::app);

    if(!fs.is_open()){
        cout << "Ошибка открытия файла" << endl;
    } else {
        Test t;
        fs << t;
    }

    fs.close();

    return 0;
}
