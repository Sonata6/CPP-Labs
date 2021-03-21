#include "RoomsInHotel.h"
#include<iostream>
#include <new> 
#include<string>
#include <vector>
using namespace::std;

RoomsInHotel RoomsInHotel::operator=(RoomsInHotel op2)  // ���������� ��������� ������������
{
	try
	{
		PeopleInRoom = new string[op2.NumOfPeople];
	}
	catch (bad_alloc & ba)
	{
		cerr << ba.what() << std::endl;
	}
	for (int i = 0; i < op2.NumOfPeople; i++)
		PeopleInRoom[i] = op2.PeopleInRoom[i];
	NumOfPeople = op2.NumOfPeople;
	RoomNumber = op2.RoomNumber;
	FloorNumber = op2.FloorNumber;
	IsAvailable = op2.IsAvailable;
	RoomPrice = op2.RoomPrice;
	return *this;
}

bool RoomsInHotel::operator==(RoomsInHotel op2)        // ���������� ��������� ���������
{
	bool b = true;
	if (NumOfPeople == op2.NumOfPeople && RoomNumber == op2.RoomNumber && FloorNumber == op2.FloorNumber && IsAvailable == op2.IsAvailable && RoomPrice == op2.RoomPrice)
		b = true;
	else
		b = false;
	for (int i = 0; i < op2.NumOfPeople; i++)
		if (PeopleInRoom[i] != op2.PeopleInRoom[i]) b = false;
	return b;
}

bool RoomsInHotel::operator!=(RoomsInHotel op2)              // ���������� ��������� !=
{
	bool b = true;
	if (NumOfPeople == op2.NumOfPeople && RoomNumber == op2.RoomNumber && FloorNumber == op2.FloorNumber && IsAvailable == op2.IsAvailable && RoomPrice == op2.RoomPrice)
		b = true;
	else
		b = false;
	for (int i = 0; i < op2.NumOfPeople; i++)
		if (PeopleInRoom[i] != op2.PeopleInRoom[i]) b = false;
	return !b;
}

bool operator > (RoomsInHotel c1, RoomsInHotel c2)              // ���������� ��������� >
{
	return c1.RoomPrice > c2.RoomPrice;
}
bool operator < (RoomsInHotel c1, RoomsInHotel c2)              // ���������� ��������� <
{
	return c2.NumOfPeople < c1.NumOfPeople;
}

ostream& operator<<(ostream& stream, RoomsInHotel obj)              // ���������� ��������� ������
{
	stream << "\n���� � " << obj.GetFloorNumber() << " ������� � " << obj.GetRoomNumber() << " ";
	if (!obj.GetAvailability())
	{
		stream << "������.\n���������� �������, ������� � ������� " << obj.GetNumOfPeople() << " :" << endl;
		for (int i = 0; i < obj.GetNumOfPeople(); i++)
			stream << i+1 << ". " << obj.PeopleInRoom[i] << endl;
	}
	else stream << "��������." << endl << "����: " << obj.GetRoomPrice() << endl;
	return stream;
}

istream& operator>>(istream& stream, RoomsInHotel& obj)              // ���������� ��������� �����
{
	cout << "������� ���� �������(100-5000): ";
	while (1)
	{
		cout << endl;
		stream >> obj.RoomPrice;
		if (obj.RoomPrice > 100 && obj.RoomPrice < 5000)
			break;
		cout << "������� �������� ��������, ���������� ��� ���: ";
	}
	cout << "������� ��������?(1 - �� / 0 - ���): ";
		char i;
		do
		{
			stream >> i;
			cout << endl;
			if (i == '1' || i == '0')
				break;
			cout << "������� �������� ��������, ���������� ��� ���: ";
			rewind(stdin);
		} while (1);
		if (i == '1')
			obj.IsAvailable = true;
		else obj.IsAvailable = false;
	if (!obj.IsAvailable)
	{
		cout << "������� ���������� ������� � ������� ";
		stream >> obj.NumOfPeople;
		obj.PeopleInRoom = new string[obj.NumOfPeople];
		for (int i = 0; i < obj.NumOfPeople; i++)
		{
			cout << "������� ��� �������� ����� " << i + 1 << ": ";
			rewind(stdin);
			getline(stream, obj.PeopleInRoom[i]);
		}
	}
	else obj.NumOfPeople = 0;
	return stream;
}