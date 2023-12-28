//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_INVALIDPOSITION_H
#define HOUSE_SIMULATOR_INVALIDPOSITION_H

#include <exception>

class invalidPosition : public std::exception {
public:
    invalidPosition() noexcept = default;

    ~invalidPosition() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "You can't create a room on that position because the position specified doesn't belong to the house.";
    }
};


#endif //HOUSE_SIMULATOR_INVALIDPOSITION_H
