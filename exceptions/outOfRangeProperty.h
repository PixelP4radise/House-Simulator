//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_OUTOFRANGEPROPERTY_H
#define HOUSE_SIMULATOR_OUTOFRANGEPROPERTY_H

#include <exception>

class outOfRangeProperty : public std::exception {
public:
    outOfRangeProperty() noexcept = default;

    ~outOfRangeProperty() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The value specified doesn't belong in the range for the specified property.";
    }
};


#endif //HOUSE_SIMULATOR_OUTOFRANGEPROPERTY_H
