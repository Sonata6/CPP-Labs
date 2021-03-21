#pragma once
#include "MyException.h";
#include <string>

using namespace std;

class NullReferenceException : public MyException
{
public:
    NullReferenceException(string str)
    {
        message = str;
    }
    NullReferenceException()
    {
        message = "Возникло исключение NullReferenceException";
    }
    void getException()
    {
        cout << message;
    }
};