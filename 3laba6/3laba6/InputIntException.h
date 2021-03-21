#pragma once
#include "MyException.h";
#include <string>

using namespace std;

class InputIntException : public MyException
{
public:
    InputIntException(string str)
    {
        message = str;
    }
    InputIntException()
    {
        message = "Возникло исключение InputIntException";
    }
    void getException()
    {
        cout << message;
    }
};