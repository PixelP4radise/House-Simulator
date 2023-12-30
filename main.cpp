#include <iostream>
#include "headerFiles/house.h"

int main() {
    house fireHouse;
    fireHouse.newRoom(1, 1);
    fireHouse.newComponent("r0", 'p', "liga");
    std::cout << fireHouse.describeRoom("r0");
    return 0;
}