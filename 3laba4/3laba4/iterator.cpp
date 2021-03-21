#include<iostream>
#include"iterator.h"
#include "dynamicms.h"
using namespace std;



template<class T>
Iterator<T>::Iterator(T* pointer)
{
    myarray = pointer;
}

template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& iter)
{
    if (this == &iter)
        return *this;
    this->myarray = iter.myarray;
    return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
    this->myarray++;
    return*this;
}

template<class T>
Iterator<T>& Iterator<T>::operator--()
{
    this->myarray--;
    return*this;
}

template<class T>
T& Iterator<T>::operator*()
{
    return *this->myarray;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& iter)
{
    return this->myarray == iter.myarray;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
    return !(*this == iter);
}