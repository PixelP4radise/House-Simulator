#include <iostream>
#include "headerFiles/house.h"

int main() {
    house fireHouse;
    fireHouse.newRoom(1, 1);
    fireHouse.newRoom(1, 2);
    fireHouse.newRoom(1, 3);
    fireHouse.listRooms();
    std::string p{"r1"};
    fireHouse.deleteRoom(p);
    std::cout << std::endl;
    fireHouse.listRooms();
    return 0;
}
