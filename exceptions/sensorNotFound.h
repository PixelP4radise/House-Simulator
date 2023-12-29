//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_SENSORNOTFOUND_H
#define HOUSE_SIMULATOR_SENSORNOTFOUND_H

#include <exception>

class sensorNotFound : public std::exception {
public:
    sensorNotFound() noexcept = default;

    ~sensorNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The sensor specified wasn't found.";
    }
};


#endif //HOUSE_SIMULATOR_SENSORNOTFOUND_H
