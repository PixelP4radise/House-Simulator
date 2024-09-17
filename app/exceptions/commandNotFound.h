//
// Created by guilh on 01/01/2024.
//

#ifndef HOUSE_SIMULATOR_COMMANDNOTFOUND_H
#define HOUSE_SIMULATOR_COMMANDNOTFOUND_H

#include <exception>

class commandNotFound : public std::exception {
public:
    commandNotFound() noexcept = default;

    ~commandNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The command specified wasn't found.";
    }
};

#endif //HOUSE_SIMULATOR_COMMANDNOTFOUND_H
