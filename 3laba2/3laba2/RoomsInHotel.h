#pragma once
#ifndef RoomsInHotel_H
#define RoomsInHotel_H

#include <vector>
#include<string>
#include<iostream>
#include <new> 

using namespace::std;

class RoomsInHotel
{
private:
	string* PeopleInRoom;
	int NumOfPeople;
	int RoomNumber;
	int FloorNumber;
	bool IsAvailable;
	int RoomPrice;

public:
	// ќбъ€вление прототипов сеттеров полей класса

	void SetRoomPrice(int RoomPrice);
	void SetAvailability(bool Availability);
	void SetNumOfPeople(int NumOfPeople);

	// ќбъ€вление прототипов геттеров полей класса

	int GetRoomNumber();
	int GetFloorNumber();
	int GetRoomPrice();
	int GetNumOfPeople();
	bool GetAvailability();

	// ќбъ€вление прототипов конструкторов класса

	RoomsInHotel();
	RoomsInHotel(int RoomPrice, bool IsAvailable, int NumOfPeople);
	RoomsInHotel(const RoomsInHotel& obj);

	// ќбъ€вление прототипа деструктора класса

	~RoomsInHotel();

	// ќбъ€вление прототипов перегруженных операторов 

	RoomsInHotel operator=(RoomsInHotel op2);
	bool operator==(RoomsInHotel op2);
	bool operator!=(RoomsInHotel op2);
	friend bool operator>(RoomsInHotel c1, RoomsInHotel c2);
	friend bool operator<(RoomsInHotel c1, RoomsInHotel c2);
	friend ostream& operator<<(ostream& stream, RoomsInHotel obj);
	friend istream& operator>>(istream& stream, RoomsInHotel& obj);

	// ќбъ€вление прототипов дружественных функций дл€ работы с классом

	friend void Edit(vector<RoomsInHotel>& rooms_in_hotel, int n, int m, int price, bool isavailable, int numofpeople);
	friend void Delete(vector<RoomsInHotel>& rooms_in_hotel);
	friend void CreateRooms(vector<RoomsInHotel>& rooms_in_hotel);
	friend void Show(vector<RoomsInHotel> rooms_in_hotel);
	friend void Add(vector<RoomsInHotel>& rooms_in_hotel, RoomsInHotel room);
	friend void DeleteRoom(vector<RoomsInHotel>& rooms_in_hotel, int n, int m);

};

#endif