#include <iostream>

#define DEBUG 3

using namespace std;

int main() {

    cout << "HELLO!" << endl;

#if DEBUG > 4
    cout << "DEBUG > 4!" << endl;
#elif DEBUG < 4
    cout << "DEBUG < 4!" << endl;
#else
    cout << "DEBUG = 4!" << endl;
#endif //DEBUG

    return 0;
}
