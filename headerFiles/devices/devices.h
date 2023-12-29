//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_DEVICES_H
#define HOUSE_SIMULATOR_DEVICES_H

#include <iostream>
#include "../houseElements.h"

class devices : public houseElements {
private:
    std::string comando;
    unsigned int turnedOnFor;
public:
    [[nodiscard]]
    std::string getId() const override;
};


#endif //HOUSE_SIMULATOR_DEVICES_H
