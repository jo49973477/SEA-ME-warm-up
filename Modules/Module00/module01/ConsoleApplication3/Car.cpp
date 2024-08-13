#include <iostream>
#include "Car.h"

Car::Car() : name("default_car"), speed(60) {

}

Car::Car(std::string name, double speed): name(name), speed(speed) {
}

Car::~Car() {

}

Car::Car(const Car& car): name(car.name), speed(car.speed) {
}

Car& Car::operator= (const Car& other){
	this->name = other.name;
	this->speed = other.speed;

	return *this;
}

void Car::print() {
	std::cout << "Name: " << name << '\n';
	std::cout << "Speed: " << speed << '\n';
}

void Car::setName(std::string str) {
	name = str;
}