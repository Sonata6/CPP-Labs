#pragma once
#include"Personal.h"
#include <vector>
#include<string>
#include<iostream>
#include <new> 
using namespace std;

class Barman : public Personal
{
private:
	int brokenbottles;
	int clientserved;
public:
	Barman();

	void todaysWork();
	void editInfo();

	void showBarmanInfo();
	void showFullBarmanInfo();
};