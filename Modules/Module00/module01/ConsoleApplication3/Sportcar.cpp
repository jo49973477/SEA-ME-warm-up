#include <iostream>
#include "Car.h"
#include "Sportcar.h"

Sportcar::Sportcar(): Car(), top_speed(130){

}

Sportcar::Sportcar(string name, string model, int year, double top_speed): Car(name, model, year), top_speed(top_speed) {

}

Sportcar::~Sportcar() {

}

Sportcar::Sportcar(const Sportcar& car): Car(car) , top_speed(car.top_speed){

}

Sportcar& Sportcar::operator= (const Sportcar& other) {
	Car::operator=(other);
	this->top_speed = other.top_speed;

	return *this;
}

void Sportcar::drive() {
	Car::drive();
	std::cout << "Top-speed:" << top_speed << '\n';
}

void Sportcar::setName(std::string str) {
	Car::setName(str);
}
