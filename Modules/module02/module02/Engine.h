#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Part.h"
#include <iostream>
using namespace std;

class Engine: public Part
{
	string form;
	double displacement;
	double max_output;
	double max_torque;

public:
	Engine();
	~Engine();
	Engine(string, double, double, double);
	Engine(const Engine& engine);
	Engine& operator= (const Engine& other);
	void spec();
};

#endif 



