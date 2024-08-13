#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
    Car my_car("Volkwagen", 200);
    my_car.print();

    Car new_car(my_car);
    new_car.setName("Audi");
    new_car.print();

    Car nn_car;
    nn_car = my_car;
    my_car.setName("Porsche");
    nn_car.print();

    return 0;
}
