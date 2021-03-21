#pragma once
#include "MyException.h";
#include <string>

using namespace std;

class InputAgeException : public MyException
{
public:
    InputAgeException(string str)
    {
        message = str;
    }
    InputAgeException()
    {
        message = "�������� ���������� InputAgeException";
    }
    void getException()
    {
        cout << message;
    }
};