#pragma once
#ifndef _CAR_H
#define _CAR_H

#include <iostream>

class Car
{
	std::string name;
	double speed;

public:
	Car();
	Car(std::string name, double speed);
	~Car();
	Car(const Car& car);
	Car& operator = (const Car& other);
	void print();
	void setName(std::string str);

};

#endif


