#pragma once
#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include "Engine.h"
#include "Fueltank.h"
#include "Package.h"
#include "Wheel.h"
using namespace std;


class Car
{
	string name;
	string model;
	int cost;
	int max_speed;
	Engine engine;
	Fueltank fueltank;
	Package package;
	Wheel wheel;

public:
	Car();
	~Car();
	Car(string, string, int, int, Engine, Fueltank, Package, Wheel);
	Car(const Car& car);
	Car& operator= (const Car& other);
	void show();
};

#endif