#pragma once
#include"Reñeption.h"
#include"Barman.h"
#include"Concierge.h"
#include<iostream>
#include <new> 
#include<string>
#include <vector>
#include "RoomsInHotel.h"

using namespace::std;
class Hotel: protected Reñeption
{
private:
	string hotelname;
	Barman barman;
	vector<Concierge> concierge;
	int starsnumber;
public:
	Hotel()
	{
		starsnumber = 5;
		hotelname = "The Oberoi";
	}
	vector<RoomsInHotel> rooms_in_hotel;
	void show();
};