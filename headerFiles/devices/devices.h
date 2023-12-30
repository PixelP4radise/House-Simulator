//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_DEVICES_H
#define HOUSE_SIMULATOR_DEVICES_H

#include <iostream>
#include "../houseElements.h"

class devices : public houseElements {
private:
    std::string command;
    unsigned int turnedOnFor;
public:

    explicit devices(std::string command = "desliga");

    [[nodiscard]]
    std::string getId() const override;

    void setCommand(const std::string &newCommand);
};


#endif //HOUSE_SIMULATOR_DEVICES_H
