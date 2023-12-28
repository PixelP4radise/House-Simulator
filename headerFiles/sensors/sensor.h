//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SENSOR_H
#define HOUSE_SIMULATOR_SENSOR_H

#include "../houseElements.h"
#include "../propertys/property.h"

class sensor : public houseElements {
private:
    std::weak_ptr<property> property;
public:
    [[nodiscard]]
    std::string getId() const override;

};

// quando crio um sensor tenho que ir buscar a localizacao da propriedade a que ele esta associado


#endif //HOUSE_SIMULATOR_SENSOR_H
