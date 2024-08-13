#pragma once
#ifndef _CAR_H
#define _CAR_H

#include <iostream>
using namespace std;

class Car
{
	string name;
	string model;
	int year;

public:
	Car();
	Car(string name, string model, int year);
	~Car();
	Car(const Car& car);
	Car& operator = (const Car& other);
	void drive();
	void setName(std::string str);

};

#endif


