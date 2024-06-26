//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_DEVICES_H
#define HOUSE_SIMULATOR_DEVICES_H

#include <iostream>
#include "../houseElements.h"
#include "../propertys/humidity.h"
#include "../propertys/luminosity.h"
#include "../propertys/radiation.h"
#include "../propertys/smoke.h"
#include "../propertys/sound.h"
#include "../propertys/temperature.h"
#include "../propertys/vibration.h"

class devices : public houseElements {
private:
    std::string command;
    unsigned int ticksSinceLastCommand;
public:
    explicit devices(std::string command = "off");

    ~devices() override = default;

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    unsigned int getTicksSinceLastCommand() const;

    void incTicksSinceLastCommand();

    void zeroTicksSinceLastCommand();

    [[nodiscard]]
    std::string getCommand() const;

    virtual void carryOut() = 0;

    void setCommand(const std::string &newCommand);
};


#endif //HOUSE_SIMULATOR_DEVICES_H
