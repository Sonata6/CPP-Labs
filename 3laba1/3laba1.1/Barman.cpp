#include"Personal.h"
#include "Barman.h"
#include <vector>
#include<string>
#include<iostream>
#include <new> 
namespace BarmanName
{
	string Name[16]{ "Maksim", "Aleksandr", "Danila", "Alexey", "Kirill", "Sergey",
	"Nikita", "Andrey", "Artem", "Dmitriy", "Mihail", "Petr", "Pavel", "Egor", "Ilya", "Matvey" };

	string Surname[16]{ "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov", "Mihailov",
	"Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov" };

	string Patronymic[16]{ "Aleksandrovich", "Danilovich", "Alexeyevich", "Kirillovich", "Sergeyevich", "Nikitich",
	"Andreyevich", "Artemovich", "Dmitriyevich", "Mihailovich", "Petrovich", "Pavlovich", "Egorovich", "Ilyich", "Matveyevich", "Danilovich" };
}
using namespace std;


void Barman::todaysWork()
{
	int i = rand() % 3;
	if (brokenbottles >= 7)
	{
		cout << "������� ������ ����� " << brokenbottles << " �������. ������� ����� �� �������...";
	return;
	}
	if (clientserved < 30)
	{
		cout << "����� �������, �� ������� ����� �� ���� �����...";
		return;
	}
	switch (i)
	{
	case 0: cout << "������� ��� ������� ����, �������� ���������, ������� ��������� � �����, ��� � ������� ��������"; break;
	case 1: cout << "����! ������� ����� ������� �� ������. ��� ���� ����� ��������� � ������� �����"; break;
	case 2: cout << "�������� �������� �������. ������ � ����� ��� ��� �� �����������..."; break;
	}
}

Barman::Barman()
{
	workinghours = 12;
	workexp = (rand() % 40 + 30)/10;
	position = "������";
	personalinf = BarmanName::Name[rand()%16]+" "+ BarmanName::Surname[rand() % 16]+" "+ BarmanName::Patronymic[rand() % 16];
	age = rand() % 16 + 14 + workexp;
	clientserved = rand() % 123 + 15;
	brokenbottles = rand() % 10;
	salary = (workinghours * workexp) * 5 + clientserved * 2 - brokenbottles * 5;
}

void Barman::editInfo()
{
	cout << "��� �� ������ ��������? 0 - ��������, 1 - �������� ������" << endl;
	bool b;
	cin >> b;
	if (b)
	{
		cout << "������� ���������� ������� �����(6-14): ";
		int i;
		do
		{
			rewind(stdin);
			cin >> i;
			if (i < 6 && i>14)
				cout << "K��������� ������� ����� ������� �������. ���������� �����: ";
				rewind(stdin);
		} while (i < 6 && i>14);
		this->workinghours = i;
	}
	else
	{
		cout << "������� ��������(300-800): ";
		int i;
		do
		{
			rewind(stdin);
			cin >> i;
			if (i < 300)
			{
				cout << "� ����� ��������� �� ����� ��������. ����� ������� �������: ";
				continue;
			}
			if (i > 800)
			{
				cout << "� ��� ��� ����� �����... ���������� ������ ���-�� ��������: ";
				continue;
			}
			rewind(stdin);
		} while (i < 300 && i>800);
		this->salary = i;
	}
}

void Barman::showBarmanInfo()
{
	cout << personalinf << " , �������: " << age << " ����(���). ���� ������: " << workexp  <<" ����(���)" << endl;
}

void Barman::showFullBarmanInfo()
{
	cout << position << ", " << personalinf << ", �������: " << age << " ����(���). \n���� ������: " << workexp << "����(���). ������� ���� - " << workinghours << " ������� �����."
		<< "�������� - " << salary << "$" << endl;
	cout << "�� ����������� ���� ���������:" << clientserved << " ��������" << endl;
	cout << "������� " << brokenbottles << " �������" << endl;
	cout << "��� ������ ��� " << personalinf << " � ����������� ���: ";
	todaysWork();
	cout << endl << endl;
}