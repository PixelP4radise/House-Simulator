//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_RULE_H
#define HOUSE_SIMULATOR_RULE_H

#include <memory>
#include "../houseElements.h"
#include "../sensors/humiditySensor.h"
#include "../sensors/luminositySensor.h"
#include "../sensors/movementSensor.h"
#include "../sensors/radiationSensor.h"
#include "../sensors/smokeSensor.h"
#include "../sensors/soundSensor.h"
#include "../sensors/temperatureSensor.h"

class rule : public houseElements {
private:
    bool state;  // a rule is either true or false
    int firstParameter;
    std::weak_ptr<sensor> detector;
public:
    explicit rule(const std::shared_ptr<sensor> &sensorPtr, int parameter1);

    [[nodiscard]]
    std::string getId() const override;

    virtual void evaluate() = 0;

    [[nodiscard]]
    std::string describeSensor() const;
};


#endif //HOUSE_SIMULATOR_RULE_H
