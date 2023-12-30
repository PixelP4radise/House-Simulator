//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SENSOR_H
#define HOUSE_SIMULATOR_SENSOR_H

#include "../houseElements.h"
#include "../propertys/humidity.h"
#include "../propertys/luminosity.h"
#include "../propertys/radiation.h"
#include "../propertys/smoke.h"
#include "../propertys/sound.h"
#include "../propertys/temperature.h"
#include "../propertys/vibration.h"
#include "../../exceptions/acessError.h"

class sensor : public houseElements {
private:
    std::weak_ptr<property> prop;
public:
    explicit sensor(const std::shared_ptr<property> &sharedPtr);

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    int getValue() const;
};

// quando crio um sensor tenho que ir buscar a localizacao da propriedade a que ele esta associado


#endif //HOUSE_SIMULATOR_SENSOR_H
