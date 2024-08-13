#include <iostream>
#include "Car.h"

Car::Car() : name("Beetle"), model("BET001"), year(1938) {

}

Car::Car(string name, string model, int year): name(name), model(model), year(year) {
}

Car::~Car() {

}

Car::Car(const Car& car): name(car.name), model(car.model), year(car.year) {
}

Car& Car::operator= (const Car& other){
	this->name = other.name;
	this->model = other.model;
	this->year = other.year;

	return *this;
}

void Car::drive() {
	std::cout << "Name:  " << name << '\n';
	std::cout << "Model: " << model << '\n';
	std::cout << "Year:  " << year << '\n';
}

void Car::setName(std::string str) {
	name = str;
}