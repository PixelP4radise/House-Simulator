//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/houseElements.h"

houseElements::houseElements() {
    static unsigned int counter{};
    num = counter++;
}

std::string houseElements::getNum() const {
    return std::to_string(num);
}