#include <iostream>
#include "Engine.h"
#include "Fueltank.h"
#include "Package.h"
#include "Wheel.h"
#include "Car.h"
using namespace std;

int main()
{
	Car car("Volkswagen Beetle", "2.0 TDI", 24595, 195, 
		Engine("Intercooled Turbo Diesel I-4", 1968, 4200, 2500),
		Fueltank("Dissel", 13.7, 18.2, 127, 55),
		Package(4280, 1810, 1485, 2537, 1578),
		Wheel("FF", "Strut/Multi-Link", "4-Wheel Disk", 215, 17, 55)
		);

	car.show();

	return 0;
}