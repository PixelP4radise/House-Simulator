//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_DEVICENOTFOUND_H
#define HOUSE_SIMULATOR_DEVICENOTFOUND_H

#include <exception>

class deviceNotFound : public std::exception {
public:
    deviceNotFound() noexcept = default;

    ~deviceNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The device specified wasn't found.";
    }
};


#endif //HOUSE_SIMULATOR_DEVICENOTFOUND_H
