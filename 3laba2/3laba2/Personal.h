#pragma once
#include <vector>
#include<string>
#include<iostream>
#include <new> 
using namespace std;

class Personal
{
protected:
	int salary;
	int workinghours;
	double workexp;
	string position;
	string personalinf;
	int age;
public:

	virtual void todaysWork() = 0;
	virtual void editInfo() = 0;

	int getSalary() { return salary; };
	int getWorkingHours() { return workinghours; };
	double getWorkExp() { return workexp; };
	string getPosition() { return position; };
	string getPersonInf() { return personalinf; };

	void setSalary(int i) { salary = i; };
};