#pragma once
#include <string>
using namespace std;
class MyException
{
protected:
    string message;
public:
    virtual void getException() = 0;
};
