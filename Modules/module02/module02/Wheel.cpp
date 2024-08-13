#include "Wheel.h"
#include "Part.h"
#include <iostream>
using namespace std;

Wheel::Wheel() :
	driving_sys("UNK"), suspension("UNK"), brake("UNK"), tire_width(0), radius(0), aspect_ratio(0){

}

Wheel::~Wheel() {
}

Wheel::Wheel(string sys, string sus, string brake, int w, int r, int ratio):
	driving_sys(sys), suspension(sus), brake(brake), tire_width(w), radius(r), aspect_ratio(ratio){
}

Wheel::Wheel(const Wheel& wheel) :
	driving_sys(wheel.driving_sys), suspension(wheel.suspension), brake(wheel.brake),
	tire_width(wheel.tire_width), radius(wheel.radius), aspect_ratio(wheel.aspect_ratio) {

}
Wheel& Wheel::operator= (const Wheel& other) {
	this->driving_sys = other.driving_sys;
	this->suspension = other.suspension;
	this->brake = other.brake;
	this->tire_width = other.tire_width;
	this->radius = other.radius;
	this->aspect_ratio = other.aspect_ratio;

	return *this;
}

void Wheel::spec() {
	cout << "------WHEEL------\n";
	cout << "Driving System: " << driving_sys << '\n';
	cout << "Suspension: " << suspension << '\n';
	cout << "Brake: " << brake << '\n';
	cout << "Tread Width: " << tire_width << "mm\n";
	cout << "Tire Radius: " << radius << "inch\n";
	cout << "Aspect Ratio: " << aspect_ratio << "%\n";
	cout << "------------------\n";
}
