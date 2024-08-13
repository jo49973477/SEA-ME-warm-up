#pragma once
#pragma once
#ifndef _WHEEL_H_
#define _WHEEL_H_

#include "Part.h"
#include <iostream>
using namespace std;

class Wheel: public Part
{
	string driving_sys;
	string suspension;
	string brake;
	int tire_width;
	int radius;
	int aspect_ratio;

public:
	Wheel();
	~Wheel();
	Wheel(string, string, string, int, int, int);
	Wheel(const Wheel& wheel);
	Wheel& operator= (const Wheel& other);
	void spec();
};

#endif