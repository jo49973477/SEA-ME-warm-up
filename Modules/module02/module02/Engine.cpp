#include "Engine.h"
#include <iostream>
using namespace std;

Engine::Engine():
	form("UNKNOWN"), displacement(0), max_output(0), max_torque(0) {

}
Engine::~Engine() {
}
Engine::Engine(string form, double dis, double max_output, double max_torque):
	form(form), displacement(dis), max_output(max_output), max_torque(max_torque){}

Engine::Engine(const Engine& engine):
	form(engine.form), displacement(engine.displacement), max_output(engine.max_output), max_torque(engine.max_torque){}

Engine& Engine::operator= (const Engine& other) {
	this->form = other.form;
	this->displacement = other.displacement;
	this->max_output = other.max_output;
	this->max_torque = other.max_torque;

	return *this;
}

void Engine::spec() {
	cout << "------ENGINE------\n";
	cout << "Form: " << form << '\n';
	cout << "Displacement " << displacement << "cc\n";
	cout << "Maximum output: " << max_output <<  "rpm\n";
	cout << "Max torque: " << max_torque << "rpm\n";
	cout << "------------------\n";
}
