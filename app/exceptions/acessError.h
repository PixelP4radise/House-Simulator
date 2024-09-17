//
// Created by guilh on 30/12/2023.
//

#ifndef HOUSE_SIMULATOR_ACESSERROR_H
#define HOUSE_SIMULATOR_ACESSERROR_H

#include <exception>

class acessError : public std::exception {
public:
    acessError() noexcept = default;

    ~acessError() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "Couldn't access it.";
    }
};


#endif //HOUSE_SIMULATOR_ACESSERROR_H
