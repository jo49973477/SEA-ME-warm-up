#pragma once
#ifndef _SPORTCAR_H
#define _SPORTCAR_H


#include <iostream>
#include "Car.h"

class Sportcar : public Car
{
	double top_speed;

public:
	Sportcar();
	Sportcar(string name, string model, int year, double top_speed);
	~Sportcar();
	Sportcar(const Sportcar& car);
	Sportcar& operator = (const Sportcar& other);
	void drive();
	void setName(std::string str);
};

#endif
