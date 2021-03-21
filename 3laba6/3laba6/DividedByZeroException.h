#pragma once
#include "MyException.h";
#include <string>

using namespace std;

class DividedByZeroException : public MyException
{
public:
    DividedByZeroException(string str)
    {
        message = str;
    }
    DividedByZeroException()
    {
        message = "Произошло деление на 0";
    }
    void getException()
    {
        cout << message;
    }
};