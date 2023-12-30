//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_HOUSEELEMENTS_H
#define HOUSE_SIMULATOR_HOUSEELEMENTS_H

#include <iostream>
#include <memory>

class houseElements {
protected:
    unsigned int num;
public:
    houseElements();

    virtual ~houseElements() = default;

    [[nodiscard]]
    std::string getNum() const;

    [[nodiscard]]
    virtual std::string getId() const = 0;

    [[nodiscard]]
    virtual std::string describe() const = 0;
};


#endif //HOUSE_SIMULATOR_HOUSEELEMENTS_H
