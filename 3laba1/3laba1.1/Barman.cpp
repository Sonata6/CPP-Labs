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
		cout << "Сегодня разбил целых " << brokenbottles << " бутылок. Надеюсь никто не заметит...";
	return;
	}
	if (clientserved < 30)
	{
		cout << "Очень странно, но сегодня почти не было людей...";
		return;
	}
	switch (i)
	{
	case 0: cout << "Сегодня был хороший день, встретил знакомого, который заселился в отель, где я работаю барменом"; break;
	case 1: cout << "Черт! Сегодня снова опоздал на работу. Ещё одно такое опоздание и выпишут штраф"; break;
	case 2: cout << "Встретил ужасного клиента. Иногда я думаю что мне не доплачивают..."; break;
	}
}

Barman::Barman()
{
	workinghours = 12;
	workexp = (rand() % 40 + 30)/10;
	position = "Бармен";
	personalinf = BarmanName::Name[rand()%16]+" "+ BarmanName::Surname[rand() % 16]+" "+ BarmanName::Patronymic[rand() % 16];
	age = rand() % 16 + 14 + workexp;
	clientserved = rand() % 123 + 15;
	brokenbottles = rand() % 10;
	salary = (workinghours * workexp) * 5 + clientserved * 2 - brokenbottles * 5;
}

void Barman::editInfo()
{
	cout << "Что вы хотите изменить? 0 - зарплата, 1 - суточный график" << endl;
	bool b;
	cin >> b;
	if (b)
	{
		cout << "Введите количество рабочих часов(6-14): ";
		int i;
		do
		{
			rewind(stdin);
			cin >> i;
			if (i < 6 && i>14)
				cout << "Kоличество рабочих часов введено неверно. Попробуйте снова: ";
				rewind(stdin);
		} while (i < 6 && i>14);
		this->workinghours = i;
	}
	else
	{
		cout << "Введите зарплату(300-800): ";
		int i;
		do
		{
			rewind(stdin);
			cin >> i;
			if (i < 300)
			{
				cout << "С такой зарплатой он точно уволится. Нужно немного поднять: ";
				continue;
			}
			if (i > 800)
			{
				cout << "У нас нет таких денег... Попробуйте ввести что-то поменьше: ";
				continue;
			}
			rewind(stdin);
		} while (i < 300 && i>800);
		this->salary = i;
	}
}

void Barman::showBarmanInfo()
{
	cout << personalinf << " , возраст: " << age << " года(лет). Стаж работы: " << workexp  <<" года(лет)" << endl;
}

void Barman::showFullBarmanInfo()
{
	cout << position << ", " << personalinf << ", возраст: " << age << " года(лет). \nСтаж работы: " << workexp << "года(лет). Рабочий день - " << workinghours << " рабочих часов."
		<< "Зарплата - " << salary << "$" << endl;
	cout << "На сегодняшний день обслужено:" << clientserved << " клиентов" << endl;
	cout << "Разбито " << brokenbottles << " бутылок" << endl;
	cout << "что думает сам " << personalinf << " о сегодняшнем дне: ";
	todaysWork();
	cout << endl << endl;
}