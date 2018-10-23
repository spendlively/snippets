#include <iostream>
#include <string.h>
#include <string>
//#include <locale.h>

using namespace std;

int main()
{

    char c = 'q';
    cout << "c = " << c << endl;



//    char string[] = {'q', 'w', 'e', '\0'};
    char string[] = "qwe";
    cout << "string = " << string << endl;
    cout << "strlen(string) = " << strlen(string) << endl;



//    setlocale(LC_ALL, "ru");
    //Символы 1-127 - символы английской клавиатуры, никогда не меняются
    //Символы 128-255 меняются с помощью setlocale()
    for (int i = 0; i < 255; ++i) {
//        cout << "code = " << i << " char = " << (char)i << endl;
    }
    cout << endl;



    //Использование указателей
    //const чтобы не было warning'а
    char const *str = "Hello!";
    cout << str << endl << endl;



    //Массив строк
    char const *strArr[] = {"Hello,", "World!"};
    for (int j = 0; j < 2; ++j) {
        cout << strArr[j] << " ";
    }
    cout << endl << endl;



    //Передача строки в функцию
    //int foo(char *str){...}



    //Конкатенация
    //В стиле си
    char str1[255] = "Hello";
    char str2[255] = "World";
    strcat(str1, str2);
    cout << str1 << endl;

    return 0;
}

