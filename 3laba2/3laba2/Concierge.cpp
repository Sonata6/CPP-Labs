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
	position = "Консьерж";
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
	case 0:cout << "И почему я не послушал маму и не пошел на программиста..."; break;
	case 1:cout << "Работаю уже " << workexp << ", но впервые вижу такие грязные комнаты."; break;
	case 2:cout << "Сегодня оставили на чай " << salary / 2 << ". Ого, да это же половина моей зарплаты!"; break;
	case 3:cout << "Скорее бы выходные..."; break;
	case 4:cout << "Ура, менеджер сказал, что если буду работать в том же духе, выдаст премию!"; break;
	case 5:cout << "Хм, а не забыл ли я выключить утюг?"; break;
	case 6:cout << "Мне кажется я нашел работу мечты."; break;
	case 7:cout << "Еще пару часиков и домой, трудный вышел денёк"; break;
	}
}

void Concierge::editInfo()
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
				cout << "У нас нет таких денег... Можете слегка уменьшить?: ";
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
	cout << "Введите номер консьержа, которого вы хотите уволить: ";
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
	cout << "Введите ФИО консьержа: ";
	rewind(stdin);
	getline(cin, con.personalinf);
	cout << "Введите возраст консьержа: ";
	rewind(stdin);
	cin >> con.age;
	cout << "Введите опыт работы консьержа: ";
	rewind(stdin);
	cin >> con.workexp;
	con.salary = (con.workinghours * con.workexp) * 5 + con.servicedrooms * 6;
	concierge.push_back(con);
}

void Concierge::showConciergesInfo()
{
	cout << personalinf << " , возраст: " << age << ". Стаж работы: " << workexp << endl;
}

void Concierge::showFullConciergesInfo()
{
	cout << position << ", " << personalinf << ", возраст: " << age << ". \nСтаж работы: " << workexp << "года(лет). Рабочий день - " << workinghours << " рабочих часов."
		<< "Зарплата - " << salary << "$" << endl;
	cout << "На сегодняшний день обслужено:" << servicedrooms << " комнат" << endl;
	cout << "что думает сам " << personalinf << " о сегодняшнем дне: ";
	todaysWork();
	cout << endl << endl;
}
