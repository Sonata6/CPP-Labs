#pragma once
#include"Personal.h"
#include <vector>
#include<string>
#include<iostream>
#include <new> 
using namespace std;
class Concierge : public Personal
{
private:
	int servicedrooms;
public:
	Concierge();

	void todaysWork();
	void editInfo();
	friend void fireConcierge(vector<Concierge>& concierge);
	friend void hireConcierge(vector<Concierge>& concierge);
	void showConciergesInfo();
	void showFullConciergesInfo();
	friend void addConcierge(vector<Concierge>& concierge);
};