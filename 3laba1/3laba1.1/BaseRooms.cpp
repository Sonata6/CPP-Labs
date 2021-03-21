#include "RoomsInHotel.h"
#include<iostream>
#include <new> 
#include<string>
#include <vector>

using namespace::std;

namespace People
{
	extern string ManName[16]{ "Maksim", "Aleksandr", "Danila", "Alexey", "Kirill", "Sergey",
	"Nikita", "Andrey", "Artem", "Dmitriy", "Mihail", "Petr", "Pavel", "Egor", "Ilya", "Matvey" };

	extern string ManSirname[16]{ "Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasiliev", "Petrov", "Sokolov", "Mihailov",
	"Novikov", "Fedorov", "Morozov", "Volkov", "Alexeev", "Lebedev", "Semenov", "Egorov" };

	extern string ManPatronymic[16]{ "Aleksandrovich", "Danilovich", "Alexeyevich", "Kirillovich", "Sergeyevich", "Nikitich",
	"Andreyevich", "Artemovich", "Dmitriyevich", "Mihailovich", "Petrovich", "Pavlovich", "Egorovich", "Ilyich", "Matveyevich", "Danilovich" };

	extern string WomanName[16]{ "Elena", "Anastasiya", "Anna", "Kseniya", "Nataliya", "Mariya", "Olga", "Alexandra",
	"Svetlana", "Sofiya", "Juliya", "Darya", "Mariya", "Polina", "Irina", "Elizaveta" };

	extern string WomanSirname[16]{ "Ivanova", "Smirnova", "Kuznecova", "Popova", "Vasilieva", "Petrova", "Sokolova",
	"Mihailova", "Novikova", "Fedorova", "Morozova", "Volkova", "Alexeeva", "Lebedeva", "Semenova", "Egorova" };

	extern string WomanPatronymic[16]{ "Aleksandrovna", "Danilovna", "Alexeyevna", "Kirillovna", "Sergeyevna", "Nikitichna",
	"Andreyevna", "Artemovna", "Dmitriyevna", "Mihailovna", "Petrovna", "Pavlovna", "Egorovna", "Ilyichna", "Matveyevna", "Alexeyevna" };
}

//Реализация сеттеров закрытых полей класса

void RoomsInHotel::SetRoomPrice(int RoomPrice) { this->RoomPrice = RoomPrice; }
void RoomsInHotel::SetAvailability(bool IsAvailable) { this->IsAvailable = IsAvailable; }
void RoomsInHotel::SetNumOfPeople(int NumOfPeople) { this->NumOfPeople = NumOfPeople; }

//Реализация геттеров закрытых полей класса

int RoomsInHotel::GetRoomNumber() { return RoomNumber; }
int RoomsInHotel::GetFloorNumber() { return FloorNumber; }
int RoomsInHotel::GetRoomPrice() { return RoomPrice; }
int RoomsInHotel::GetNumOfPeople() { return NumOfPeople; }
bool RoomsInHotel::GetAvailability() { return IsAvailable; }

RoomsInHotel::RoomsInHotel()               // Конструктор по умолчанию
{
	static int i = 1, j = 1;
	if (!(j & 3))
	{
		i++;
		j = 1;
	}
	FloorNumber = i;
	RoomNumber = j++;
	RoomPrice = (rand() % 100) * 10;
	IsAvailable = true;
	PeopleInRoom = nullptr;
}

RoomsInHotel::RoomsInHotel(int RoomPrice, bool IsAvailable, int NumOfPeople = 0)    // Конструктор с параметрами
{
	static int i = 1, j = 1;   
	if (!(j & 3))
	{
		i++;
		j = 1;
	} 
	FloorNumber = i;
	RoomNumber = j++;
	this->RoomPrice = RoomPrice;
	this->IsAvailable = IsAvailable;
	this->NumOfPeople = NumOfPeople;
	if (!IsAvailable)
	{
		try
		{
			PeopleInRoom = new string[NumOfPeople];
		}
		catch (bad_alloc & ba)
		{
			cerr << ba.what() << std::endl;
		}
		int j;
		for (int i = 0; i < NumOfPeople; i++)
		{
			j = rand() % 2;
			if (!j)	PeopleInRoom[i] = People::ManSirname[rand() % 16] + " " + People::ManName[rand() % 16] + " " + People::ManPatronymic[rand() % 16];
			else PeopleInRoom[i] = People::WomanSirname[rand() % 16] + " " + People::WomanName[rand() % 16] + " " + People::WomanPatronymic[rand() % 16];
		}
	}
	else 
	{
		NumOfPeople = 0; PeopleInRoom = nullptr;
	}
}

RoomsInHotel::RoomsInHotel(const RoomsInHotel& obj)     // Конструктор копирования
{
	if (!obj.IsAvailable) {
		try
		{
			PeopleInRoom = new string[obj.NumOfPeople];
		}
		catch (bad_alloc & ba)
		{
			cerr << ba.what() << std::endl;
		}
		for (int i = 0; i < obj.NumOfPeople; i++)
			PeopleInRoom[i] = obj.PeopleInRoom[i];
	}
	if (!obj.NumOfPeople)
		PeopleInRoom = nullptr;
	NumOfPeople = obj.NumOfPeople;
	RoomNumber = obj.RoomNumber;
	FloorNumber = obj.FloorNumber;
	IsAvailable = obj.IsAvailable;
	RoomPrice = obj.RoomPrice;
}

RoomsInHotel::~RoomsInHotel()       // Деструктор
{
	if(PeopleInRoom!= nullptr)
	delete[] PeopleInRoom;
}