#pragma once

template<class T>
class Iterator
{
private:

    T* myarray;

public:

    //Iterator(Array<T>);


    Iterator(T* pointer);

    // Перегруженные операции
    Iterator& operator=(const Iterator<T>&); // присвоение итератора
    Iterator& operator++(); // префиксный инкремент
    Iterator& operator--(); // префиксный декремент
    T& operator*(); // разыменовывание
    bool operator==(const Iterator<T>&); // истина, если равны
    bool operator!=(const Iterator<T>&); // истина, если не равны
};
template class Iterator<int>;