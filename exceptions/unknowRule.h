//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_UNKNOWRULE_H
#define HOUSE_SIMULATOR_UNKNOWRULE_H

#include <exception>

class unknowRule : public std::exception {
public:
    unknowRule() noexcept = default;

    ~unknowRule() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The rule specified doesn't exist or has the wrong number of parameters";
    }
};


#endif //HOUSE_SIMULATOR_UNKNOWRULE_H
