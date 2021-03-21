#include "RoomsInHotel.h"
#include<iostream>
#include <new> 
#include<string>
#include<vector>
using namespace::std;
namespace People2
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
void Show(vector<RoomsInHotel> rooms_in_hotel)             // Просмотр объектов массива
{
	for (int i = 0; i < rooms_in_hotel.size(); i++)
		cout << rooms_in_hotel[i];
}

void CreateRooms(vector<RoomsInHotel>& rooms_in_hotel)        // Создание объектов массива
{
	bool b;
	int price, num;
	for (int i = 0; i < 10; i++)
	{
		b = rand() % 2;
		price = rand() % 50 * 10;
		if (!b)
			num = rand() % 5 + 1;
		else num = 0;
		rooms_in_hotel.push_back(RoomsInHotel(price, b, num));
	}
}

void Add(vector<RoomsInHotel>& rooms_in_hotel, RoomsInHotel room)    // Добавление элемента в массив
{
	int i = rooms_in_hotel.size() - 1;
	if (rooms_in_hotel[i].RoomNumber == 3)
	{
		room.FloorNumber = rooms_in_hotel[i].FloorNumber + 1;
		room.RoomNumber = 1;
	}
	else
	{
		room.FloorNumber = rooms_in_hotel[i].FloorNumber;
		room.RoomNumber = rooms_in_hotel[i].RoomNumber+1;
	}
	if (room.IsAvailable)
		room.NumOfPeople = 0;
	rooms_in_hotel.push_back(RoomsInHotel(room));
}

void Edit(vector<RoomsInHotel>& rooms_in_hotel, int n,int m, int price = 0, bool isavailable = true, int numofpeople = 0)    // Изменение элементов в массиве
{
	n = (n - 1) * 3 + m;
	int j;
	if (n<0 || n>rooms_in_hotel.size())
		return;
	if (price!=rooms_in_hotel[n-1].RoomPrice)
		rooms_in_hotel[n - 1].SetRoomPrice(price);
	if (isavailable != rooms_in_hotel[n - 1].IsAvailable && !isavailable)
	{
		rooms_in_hotel[n - 1].IsAvailable = isavailable;
		rooms_in_hotel[n - 1].NumOfPeople = numofpeople;
		rooms_in_hotel[n - 1].PeopleInRoom = new string[numofpeople];
		for (int i = 0; i < numofpeople; i++)
		{
			j = rand() % 2;
			if (!j)	rooms_in_hotel[n-1].PeopleInRoom[i] = People2::ManSirname[rand() % 16] + " " + People2::ManName[rand() % 16] + " " + People2::ManPatronymic[rand() % 16];
			else rooms_in_hotel[n-1].PeopleInRoom[i] = People2::WomanSirname[rand() % 16] + " " + People2::WomanName[rand() % 16] + " " + People2::WomanPatronymic[rand() % 16];
		}
	}
	else if (isavailable != rooms_in_hotel[n - 1].IsAvailable && isavailable)
	{
		rooms_in_hotel[n - 1].IsAvailable = isavailable;
		rooms_in_hotel[n - 1].NumOfPeople = 0;
		delete[] rooms_in_hotel[n - 1].PeopleInRoom;
	}
}
void DeleteRoom(vector<RoomsInHotel>& rooms_in_hotel, int n, int m)          // Удаление комнаты
{
	int i;
	for(i=0;i<rooms_in_hotel.size();i++)
	{
		if (rooms_in_hotel[i].FloorNumber == n && rooms_in_hotel[i].RoomNumber == m)
			break;
	}
	if (rooms_in_hotel.size() > (n - 1) * 3 + m - 1)
	{
		rooms_in_hotel.erase(rooms_in_hotel.begin() + i);
		cout << "Комната " << n << " " << m << "удалена." << endl;
	}
	else cout << "Неверно введен этаж или комната" << endl;
}

void Delete(vector<RoomsInHotel>& rooms_in_hotel)              // Удаление всех комнат
{
	rooms_in_hotel.clear();
}