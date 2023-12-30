#include <iostream>
#include "headerFiles/house.h"

int main() {
    house fireHouse;
    fireHouse.newRoom(1, 1);
    fireHouse.newComponent("r0", 'p', "liga");
    fireHouse.newComponent("r0", 's', "temperature");
    fireHouse.addRule("r0", "p0", "s0", "equal_to", 90);
    fireHouse.addRule("r0", "p0", "s0", "less_than", 90);
    fireHouse.addRule("r0", "p0", "s0", "greater_than", 90);
    fireHouse.addRule("r0", "p0", "s0", "in_between", 90, 100);
    fireHouse.saveProcessor("r0", "p0", "ola");
    fireHouse.removeComponent("r0", 'p', "p0");
    fireHouse.restoreProcessor("ola");
    std::cout << fireHouse.describeRoom("r0") << std::endl;
    return 0;
}