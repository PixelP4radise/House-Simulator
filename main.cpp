#include <iostream>
#include "headerFiles/house.h"

int main() {
    house fireHouse;
    fireHouse.newRoom(1, 1);
    fireHouse.newComponent("r0", 'p', "on");
    fireHouse.newComponent("r0", 'd', "heater");
    fireHouse.associateDeviceToProcessor("r0", "p0", "d0");
    fireHouse.newComponent("r0", 's', "temperature");
    fireHouse.addRule("r0", "p0", "s0", "less_than", 5);
    fireHouse.newComponent("r0", 'p', "off");
    fireHouse.associateDeviceToProcessor("r0", "p1", "d0");
    fireHouse.addRule("r0", "p1", "s0", "greater_than", 5);
    std::cout << fireHouse.showPropertysOfRoom("r0") << std::endl;
    for (int i = 0; i < 20; ++i) {
        fireHouse.carryOut();
        std::cout << fireHouse.showPropertysOfRoom("r0") << std::endl;
    }


    return 0;
}