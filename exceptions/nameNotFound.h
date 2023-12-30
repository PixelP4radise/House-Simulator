//
// Created by guilh on 30/12/2023.
//

#ifndef HOUSE_SIMULATOR_NAMENOTFOUND_H
#define HOUSE_SIMULATOR_NAMENOTFOUND_H

#include <exception>

class nameNotFound : public std::exception {
public:
    nameNotFound() noexcept = default;

    ~nameNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The name specified wasn't found in memory";
    }
};

#endif //HOUSE_SIMULATOR_NAMENOTFOUND_H
