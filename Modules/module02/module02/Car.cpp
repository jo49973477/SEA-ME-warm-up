#include <iostream>
#include "Engine.h"
#include "Fueltank.h"
#include "Package.h"
#include "Wheel.h"
#include "Car.h"
using namespace std;

Car::Car():name("Unknown"), model("Unknown"), cost(0), max_speed(0),
engine(Engine()), fueltank(Fueltank()), package(Package()), wheel(Wheel()) {}

Car::~Car() {}

Car::Car(string name, string model, int cost, int max_speed, Engine e, Fueltank f, Package p, Wheel w):
	name(name), model(model), cost(cost), max_speed(max_speed), 
	engine(e), fueltank(f), package(p), wheel(w){}

Car::Car(const Car& car) :
	name(car.name), model(car.model), cost(car.cost), max_speed(car.max_speed),
	engine(car.engine), fueltank(car.fueltank), package(car.package), wheel(car.wheel) {}

Car& Car::operator= (const Car& other) {
	this->name = other.name;
	this->model = other.model;
	this->cost = other.cost;
	this->max_speed = other.max_speed;
	this->engine = other.engine;
	this->fueltank = other.fueltank;
	this->wheel = other.wheel;

	return *this;
}

void Car::show() {
	cout << "-----THE SPEC OF " << name << ' ' << model << "-----\n";
	cout << "COST: $" << cost << "\n";
	cout << "Maximum speed: " << max_speed << "km/h\n";
	engine.spec();
	fueltank.spec();
	package.spec();
	wheel.spec();
}