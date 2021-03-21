#pragma once

template<class T>
class Iterator
{
private:

    T* myarray;

public:

    //Iterator(Array<T>);


    Iterator(T* pointer);

    // ������������� ��������
    Iterator& operator=(const Iterator<T>&); // ���������� ���������
    Iterator& operator++(); // ���������� ���������
    Iterator& operator--(); // ���������� ���������
    T& operator*(); // ���������������
    bool operator==(const Iterator<T>&); // ������, ���� �����
    bool operator!=(const Iterator<T>&); // ������, ���� �� �����
};
template class Iterator<int>;