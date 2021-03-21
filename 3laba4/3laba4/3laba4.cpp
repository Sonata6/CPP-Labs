#include <iostream>
#include"dynamicms.h"
#include"iterator.h"
int main()
{
    Array<int> myarray(2);
    Iterator<int> iter(myarray.getArray());
    setlocale(LC_ALL, "Ru");
    for(int i = 0;i<10;i++)
        myarray._pushBack(i);
    ++iter;
    *iter = 228;
    ++iter;
    *iter = 228;
    myarray._show();
    if (*iter == 228) cout << "== работает корректно" << endl;
    ++iter;
    if (*iter != 228) cout << "!= работает корректно" << endl;

    cout << myarray._getFirst() << endl;
    cout << myarray._getLast() << endl;

    if (myarray._isEmpty()) cout << "Массив пуст" << endl;
    else cout << "Массив не пуст" << endl;

    cout << "Размер массива: " << myarray._size() << endl;

    myarray._swap(1, 9);
    myarray._show();
    
    myarray._popBack();
    myarray._show();

    cout << "Размер массива: " << myarray._size() << endl;

}
