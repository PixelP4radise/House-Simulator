//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_INVALIDDEVICETYPE_H
#define HOUSE_SIMULATOR_INVALIDDEVICETYPE_H

#include <exception>

class invalidDeviceType : public std::exception {
public:
    invalidDeviceType() noexcept = default;

    ~invalidDeviceType() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The device type specified is invalid.";
    }
};


#endif //HOUSE_SIMULATOR_INVALIDDEVICETYPE_H
