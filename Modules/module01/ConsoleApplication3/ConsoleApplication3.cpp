#include <iostream>
#include <memory>
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

    shared_ptr<Sportcar> ptr01(new Sportcar("XL Sport Concept", "XLS492", 2014, 270));
    ptr01 -> drive();

    shared_ptr<Sportcar> ptr02(new Sportcar());
    shared_ptr<Sportcar> ptr03(new Sportcar(*ptr02));

    ptr02-> drive();
    ptr03-> drive();

    cout << "ptr02: " << ptr02.use_count() << endl;
    cout << "ptr03: " << ptr03.use_count() << endl;

    shared_ptr<Sportcar> ptr04 = ptr02;
    shared_ptr<Sportcar> ptr05;
    ptr05 = ptr03;

    cout << "ptr02: " << ptr02.use_count() << endl;
    cout << "ptr03: " << ptr03.use_count() << endl;

    return 0;
}
