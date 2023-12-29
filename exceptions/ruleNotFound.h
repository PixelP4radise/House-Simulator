//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_RULENOTFOUND_H
#define HOUSE_SIMULATOR_RULENOTFOUND_H

#include <exception>

class ruleNotFound : public std::exception {
public:
    ruleNotFound() noexcept = default;

    ~ruleNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The rule specified wasn't found.";
    }
};


#endif //HOUSE_SIMULATOR_RULENOTFOUND_H
