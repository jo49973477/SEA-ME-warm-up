#include "Package.h"


Package::Package():
	all_len(0), all_width(0), all_height(0), wheel_base(0), tread(0){
}


Package::~Package() {
}


Package::Package(int l, int w, int h, int base, int tread):
	all_len(l), all_width(w), all_height(h), wheel_base(base), tread(tread){
}

Package::Package(const Package& p) :
	all_len(p.all_len), all_width(p.all_width), all_height(p.all_height), 
	wheel_base(p.wheel_base), tread(tread) {

}

Package& Package::operator= (const Package& other) {
	this->all_len = other.all_len;
	this->all_width = other.all_width;
	this->all_height = other.all_height;
	this->wheel_base = other.wheel_base;
	this->tread = other.tread;

	return *this;
}

void Package::spec() {
	cout << "-----PACKAGE-----\n";
	cout << "Overall Length: " << all_len << "mm\n";
	cout << "Overall width: " << all_width << "mm\n";
	cout << "Overall height: " << all_height << "mm\n";
	cout << "Wheel base: " << wheel_base << "mm\n";
	cout << "Tread: " << tread << "mm\n";
	cout << "------------------\n";
}