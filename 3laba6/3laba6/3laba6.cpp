#include <iostream>
#include "NullReferenceException.h";
#include "DividedByZeroException.h";
#include "InputIntException.h";
#include "IndexOutOfRangeException.h";
#include "InputAgeException.h";
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        int dividend, divider;
        cout << "Введите делитель и делимое:\n";
        cin >> dividend;
        cin >> divider;
        if (divider == 0) throw DividedByZeroException();
        cout << "Частное равно: " << dividend / divider << endl;

        int ms[3] = { 0, 1, 2 }, n;
        cout << "\nВведите номер элемента массива, к которому вы хотите обратиться (от 0 до 2): ";
        cin >> n;
        if (n > 2 || n < 0) throw IndexOutOfRangeException();
        cout << "Значение " << n << " элемента массива = " << ms[n] << endl;

        cout << "\nВведите возраст человека: ";
        cin >> n;
        if (n < 0 || n>100) throw InputAgeException();
        if (n > 18) cout << "Человек совершеннолетний\n";
        else cout << "Человек несовершеннолетний" << endl;

        cout << "\nВведите целочисленное значение: ";
        cin >> n;
        if (cin.fail()) throw InputIntException();
        cout << "Вы ввели число " << n << endl;

        string str;
        cout << "\nВведите строку: ";
        cin >> str;
        if (str == "") throw NullReferenceException();
        cout << "Вы написали: " << str;
    }
    catch (NullReferenceException ex)
    {
        ex.getException();
    }
    catch (DividedByZeroException ex)
    {
        ex.getException();
    }
    catch (IndexOutOfRangeException ex)
    {
        ex.getException();
    }
    catch (InputAgeException ex)
    {
       ex.getException();
    }
    catch (InputIntException ex)
    {
        ex.getException();
    }
    catch (exception ex)
    {
        ex.what();
    }
}
