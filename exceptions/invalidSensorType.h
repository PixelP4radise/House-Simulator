//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_INVALIDSENSORTYPE_H
#define HOUSE_SIMULATOR_INVALIDSENSORTYPE_H

#include <exception>

class invalidSensorType : public std::exception {
public:
    invalidSensorType() noexcept = default;

    ~invalidSensorType() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The type of sensor specified can't be created.";
    }
};


#endif //HOUSE_SIMULATOR_INVALIDSENSORTYPE_H
