#ifndef CLASSSEQUENCE_HANDLERS_H
#define CLASSSEQUENCE_HANDLERS_H
#include <iostream>
#include <limits>
using namespace std;
const int UNINITIALIZED = -99999;


int handlerIndex(int index, int arraySize);

template<typename T>
int handlerUninitialized(int index, T el);

int handlerSize(int size);
int handlerInput(int* variant);
int handlerInput(int *var, int rangeOne, int rangeTwo);
char get_first_char();

bool IsNumber(const string& str);
template<typename T>
string input_type(T input);

class IndexOutOfRange {
private:
    string error_message_;
public:
    IndexOutOfRange(const string& error_message) : error_message_(error_message) {}

    const string& GetErrorMessage();
};





int handlerIndex(int index, int arraySize) {
    try {
        if (index < 0 || index >= arraySize) {
            throw "INDEX OUT OF RANGE";
        }
        return index;
    } catch (const char* errorMsg) {
        cout << "Error: " << errorMsg << endl;
        exit(-1);
    }
}


template<typename T>
int handlerUninitialized(int index, T el) {
    try {
        if (el == UNINITIALIZED) {
            throw "THERE IS NO ELEMENT AT THIS INDEX";
        }
        return index;
    } catch (const char* errorMsg) {
        cout << "Error: " << errorMsg << endl;
        exit(-1);
    }
}


int handlerSize(int size) {
    try {
        if (size <= 0) {
            throw "SIZE < 0";
        }
        return size;
    } catch (const char* errorMsg) {
        cout << "Error: " << errorMsg << endl;
        return -1;
    }
}


const string &IndexOutOfRange::GetErrorMessage() {
    return error_message_;
}


int handlerInput(int* variant) {
    int check_scan;
    do {
        check_scan = scanf_s("%d", variant);
        if (check_scan == EOF || check_scan < 0) {
            cout << "\nEOF\n";
            return -1;
        }
        if (check_scan == 0) {
            cout << "Incorrect input, try again:";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (check_scan != 1);
    return 1;
}

int handlerInput(int *var, int rangeOne, int rangeTwo){
    int flag = 0;

    do {
        flag = 0;
        handlerInput(var);
        if (*var > rangeTwo || *var <= rangeOne - 1){
            flag = 1;
            cout << "This option is not in the list, please enter a number from " << rangeOne << " to " << rangeTwo << ": ";
        }
    } while (flag == 1);

    return 0;
}
#endif //CLASSSEQUENCE_HANDLERS_H
