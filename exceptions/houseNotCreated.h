//
// Created by guilh on 02/01/2024.
//

#ifndef HOUSE_SIMULATOR_HOUSENOTCREATED_H
#define HOUSE_SIMULATOR_HOUSENOTCREATED_H

#include <exception>

class houseNotCreated : public std::exception {
public:
    houseNotCreated() noexcept = default;

    ~houseNotCreated() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The simulation hasn't been created.";
    }
};


#endif //HOUSE_SIMULATOR_HOUSENOTCREATED_H
