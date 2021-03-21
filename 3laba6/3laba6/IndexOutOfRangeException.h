#pragma once
#include "MyException.h";
#include <string>

using namespace std;

class IndexOutOfRangeException : public MyException
{
public:
    IndexOutOfRangeException(string str)
    {
        message = str;
    }
    IndexOutOfRangeException()
    {
        message = "�� ����� �� ������� �������";
    }
    void getException()
    {
        cout << message;
    }
};