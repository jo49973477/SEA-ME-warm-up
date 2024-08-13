#include <iostream>
#include "Car.h"
#include "Sportcar.h"
using namespace std;

int main()
{
    Car my_car("Volkwagen", "WKW001", 200);
    my_car.drive();

    Car new_car(my_car);
    new_car.setName("Audi");
    new_car.drive();

    Sportcar my_spcar("XL Sport Concept", "XLS492", 2014, 270);
    my_spcar.drive();

    Sportcar old_spcar;
    Sportcar new_spcar(old_spcar);
    new_spcar.setName("New Beetle");


    old_spcar.drive();
    new_spcar.drive();

    return 0;
}
