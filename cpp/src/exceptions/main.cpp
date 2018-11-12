#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void throwIfstreamException();

void throwIntException();

void throwStdExceptionException();

void throwCustomException();

class CustomException : public std::exception {
public:
    explicit CustomException(const char *message) :
            msg_(message) {}

    explicit CustomException(const std::string &message) :
            msg_(message) {}

    virtual ~CustomException() throw() {}

    virtual const char *what() const throw() {
        return msg_.c_str();
    }

protected:
    std::string msg_;
};

int main() {

//    throwIfstreamException();

//    throwIntException();

//    throwStdExceptionException();

    throwCustomException();

    return 0;
}

void throwCustomException() {

    try {
        throw CustomException("My error");
    } catch (CustomException &e) {
        cout << e.what() << endl;
    } catch (std::exception &e) {
        cout << "e.what()" << endl;
    }
}

void throwStdExceptionException() {

    try {
        throw std::runtime_error("error");
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }
}

void throwIntException() {

    try {
        throw 666;
    } catch (const int e) {
        cout << e << endl;
    }
}

void throwIfstreamException() {

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try {
        fin.open("filename");
//    } catch (const std::exception &e) {
    } catch (const ifstream::failure &e) {
        cout << e.what() << endl;
        cout << e.code() << endl;
    }
}
