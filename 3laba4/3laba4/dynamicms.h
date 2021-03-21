#pragma once
#include"iterator.h"
#include<iostream>

using namespace std;

template <class T>
class Array
{
    T* array; // массив
    unsigned size; // размер
    unsigned fullsize;

public:
    Array();
    Array(int size);
    Array(int size, int k);
    T _getFirst();
    T _getLast();
    bool _isEmpty();
    unsigned _size();
    void _swap(int a, int b);
    void _pushBack(T val);
    void _popBack();
    void _deleteAll();
    void _addCapacity();
    void _checkCapacity();
    void _show();
    int operator[](int i) { return array[i]; }
    T* getArray() { return array; }
    ~Array();

};
template class Array<int>;