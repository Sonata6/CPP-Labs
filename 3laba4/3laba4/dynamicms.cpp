#include<iostream>
#include"dynamicms.h"
using namespace std;


template<class T>
Array<T>::Array()
{
    array = nullptr;
    size = 0;
    fullsize = 0;
}

template<class T>
Array<T>::Array(int size)
{
    this->size = 0;
    fullsize = size * 2 + 10;
    try
    {
        array = new T[fullsize];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "Ошибка выделения памяти: " << ba.what() << '\n';
    }
}

template<class T>
Array<T>::Array(int size, int k)
{

        this->size = size;
        fullsize = size * 2 + 10;
        try
        {
            array = new T[fullsize];
        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "Ошибка выделения памяти: " << ba.what() << '\n';
        }
            for (int i = 0; i < size; i++)
            {
                array[i] = k;
            }
}

template<class T>
Array<T>::~Array()
{
    try
    {
        delete[] array;
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "Ошибка очищения памяти: " << ba.what() << '\n';
    }
}

template<class T>
T Array<T>::_getFirst()
{
    if(!_isEmpty())
    return array[0];
}

template<class T>
T Array<T>::_getLast()
{
    if (!_isEmpty())
        return array[size-1];
}

template<class T>
bool Array<T>::_isEmpty()
{
    if (!size)
        return true;
    return false;
}

template<class T>
unsigned Array<T>::_size()
{
    return size;
}

template<class T>
void Array<T>::_swap(int a, int b)
{
    T tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

template<class T>
void Array<T>::_pushBack(T val)
{
    _checkCapacity();
    array[size] = val;
    size++;
}

template<class T>
void Array<T>::_popBack()
{
    size--;
}

template<class T>
void Array<T>::_deleteAll()
{
    size = 0;
    try
    {
        delete[] array;
        array = new T[2];
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "Ошибка выделения памяти: " << ba.what() << '\n';
    }
}

template<class T>
void Array<T>::_show()
{
    int i;
    for (i = 0; i < size-1; i++)
        cout << array[i] << ", ";
    cout << array[i] << "." << endl;
}

template<class T>
void Array<T>::_checkCapacity()
{
    if (size >= fullsize)
        _addCapacity();
}

template<class T>
void Array<T>::_addCapacity()
{
    fullsize = size * 2 + 10;
    try
    {
        T* array1 = new T[fullsize];
        for (int i = 0; i < size; i++)
            array1[i] = array[i];
        delete[] array;
        array = array1;
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "Ошибка выделения памяти: " << ba.what() << '\n';
    }
}