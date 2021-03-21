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
        cout << "������� �������� � �������:\n";
        cin >> dividend;
        cin >> divider;
        if (divider == 0) throw DividedByZeroException();
        cout << "������� �����: " << dividend / divider << endl;

        int ms[3] = { 0, 1, 2 }, n;
        cout << "\n������� ����� �������� �������, � �������� �� ������ ���������� (�� 0 �� 2): ";
        cin >> n;
        if (n > 2 || n < 0) throw IndexOutOfRangeException();
        cout << "�������� " << n << " �������� ������� = " << ms[n] << endl;

        cout << "\n������� ������� ��������: ";
        cin >> n;
        if (n < 0 || n>100) throw InputAgeException();
        if (n > 18) cout << "������� ����������������\n";
        else cout << "������� ������������������" << endl;

        cout << "\n������� ������������� ��������: ";
        cin >> n;
        if (cin.fail()) throw InputIntException();
        cout << "�� ����� ����� " << n << endl;

        string str;
        cout << "\n������� ������: ";
        cin >> str;
        if (str == "") throw NullReferenceException();
        cout << "�� ��������: " << str;
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
