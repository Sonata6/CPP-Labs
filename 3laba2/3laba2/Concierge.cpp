#include"Personal.h"
#include "Concierge.h"
#include <vector>
#include<string>
#include<iostream>
#include <new> 
namespace ConciergeName
{
	string Name[16]{ "Maksim", "Aleksandr", "Danila", "Alexey", "Kirill", "Sergey",
	"Nikita", "Andrey", "Artem", "Dmitriy", "Mihail", "Petr", "Pavel", "Egor", "Ilya", "Matvey" };

	string Surname[16]{ "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov", "Mihailov",
	"Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov" };

	string Patronymic[16]{ "Aleksandrovich", "Danilovich", "Alexeyevich", "Kirillovich", "Sergeyevich", "Nikitich",
	"Andreyevich", "Artemovich", "Dmitriyevich", "Mihailovich", "Petrovich", "Pavlovich", "Egorovich", "Ilyich", "Matveyevich", "Danilovich" };
}
using namespace std;


Concierge::Concierge()
{
	workinghours = 8;
	workexp = (rand() % 40 + 30) / 10;
	position = "��������";
	personalinf = ConciergeName::Name[rand() % 16] + " " + ConciergeName::Surname[rand() % 16] + " " + ConciergeName::Patronymic[rand() % 16];
	age = rand() % 16 + 14 + workexp;
	servicedrooms = rand() % 12 + 6;
	salary = (workinghours * workexp) * 5 + servicedrooms * 6;
}

void Concierge::todaysWork()
{
	int i = rand() % 8;
	switch (i)
	{
	case 0:cout << "� ������ � �� �������� ���� � �� ����� �� ������������..."; break;
	case 1:cout << "������� ��� " << workexp << ", �� ������� ���� ����� ������� �������."; break;
	case 2:cout << "������� �������� �� ��� " << salary / 2 << ". ���, �� ��� �� �������� ���� ��������!"; break;
	case 3:cout << "������ �� ��������..."; break;
	case 4:cout << "���, �������� ������, ��� ���� ���� �������� � ��� �� ����, ������ ������!"; break;
	case 5:cout << "��, � �� ����� �� � ��������� ����?"; break;
	case 6:cout << "��� ������� � ����� ������ �����."; break;
	case 7:cout << "��� ���� ������� � �����, ������� ����� ����"; break;
	}
}

void Concierge::editInfo()
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
				cout << "� ��� ��� ����� �����... ������ ������ ���������?: ";
				continue;
			}
			rewind(stdin);
		} while (i < 6 && i>14);
		this->salary = i;
	}
}

void fireConcierge(vector<Concierge>& concierge)
{
	int n;
	cout << "������� ����� ���������, �������� �� ������ �������: ";
	rewind(stdin);
	cin >> n;
	concierge.erase(concierge.begin() + n - 1);
}

void addConcierge(vector<Concierge>& concierge)
{
	for (int i = 0; i < 3; i++)
	{
		Concierge con;
		concierge.push_back(con);
	}
	cout << concierge.size();
}

void hireConcierge(vector<Concierge>& concierge)
{
	Concierge con;
	cout << "������� ��� ���������: ";
	rewind(stdin);
	getline(cin, con.personalinf);
	cout << "������� ������� ���������: ";
	rewind(stdin);
	cin >> con.age;
	cout << "������� ���� ������ ���������: ";
	rewind(stdin);
	cin >> con.workexp;
	con.salary = (con.workinghours * con.workexp) * 5 + con.servicedrooms * 6;
	concierge.push_back(con);
}

void Concierge::showConciergesInfo()
{
	cout << personalinf << " , �������: " << age << ". ���� ������: " << workexp << endl;
}

void Concierge::showFullConciergesInfo()
{
	cout << position << ", " << personalinf << ", �������: " << age << ". \n���� ������: " << workexp << "����(���). ������� ���� - " << workinghours << " ������� �����."
		<< "�������� - " << salary << "$" << endl;
	cout << "�� ����������� ���� ���������:" << servicedrooms << " ������" << endl;
	cout << "��� ������ ��� " << personalinf << " � ����������� ���: ";
	todaysWork();
	cout << endl << endl;
}
