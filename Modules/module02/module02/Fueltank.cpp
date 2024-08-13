#include "Fueltank.h"
#include <iostream>
using namespace std;

Fueltank::Fueltank():
	fuel("unknown"), city_fe(0), hw_fe(0), co2(0), tank(0){}

Fueltank::~Fueltank(){}

Fueltank::Fueltank(string fuel, double city_fe, double hw_fe, double co2, int tank) :
	fuel(fuel), city_fe(city_fe), hw_fe(hw_fe), co2(co2), tank(tank) {}

Fueltank::Fueltank(const Fueltank& tank):
	fuel(tank.fuel), city_fe(tank.city_fe), hw_fe(tank.hw_fe), co2(tank.co2), tank(tank.tank) {

}

Fueltank& Fueltank::operator= (const Fueltank& other) {
	this->fuel = other.fuel;
	this->city_fe = other.city_fe;
	this->hw_fe = other.hw_fe;
	this->co2 = other.co2;
	this->tank = other.tank;

	return *this;
}

void Fueltank::spec() {
	cout << "----FUEL-TANK----\n";
	cout << "Fuel: " << fuel << "km/l\n";
	cout << "City Fuel Efficiency: " << city_fe << "km/l\n";
	cout << "Highway Fuel Efficiency: " << hw_fe << "km/l\n";
	cout << "CO2 Emmision: " << co2 << "g/km\n";
	cout << "Fuel Tank Capacity: " << tank << "l\n";
	cout << "----FUEL-TANK-----\n";
}