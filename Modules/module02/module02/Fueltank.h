#pragma once
#ifndef _FUELTANK_H_
#define _FUELTANK_H_

#include "Part.h"
#include <iostream>
using namespace std;

class Fueltank: public Part
{	
	string fuel;
	double city_fe;
	double hw_fe;
	double co2;
	int tank;

public:
	Fueltank();
	~Fueltank();
	Fueltank(string, double, double, double, int);
	Fueltank(const Fueltank& tank);
	Fueltank& operator= (const Fueltank& other);
	void spec();
};

#endif 

