//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_HOUSEELEMENTS_H
#define HOUSE_SIMULATOR_HOUSEELEMENTS_H

#include <iostream>
#include <memory>

class houseElements {
private:
    unsigned int num;
public:
    houseElements();

    virtual ~houseElements() = default;

    std::string getNum() const;

    virtual std::string getId() const = 0;

    virtual std::string describe() const = 0;
};


#endif //HOUSE_SIMULATOR_HOUSEELEMENTS_H
