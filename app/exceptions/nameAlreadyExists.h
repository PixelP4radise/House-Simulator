//
// Created by guilh on 30/12/2023.
//

#ifndef HOUSE_SIMULATOR_NAMEALREADYEXISTS_H
#define HOUSE_SIMULATOR_NAMEALREADYEXISTS_H

#include <exception>

class nameAlreadyExists : public std::exception {
public:
    nameAlreadyExists() noexcept = default;

    ~nameAlreadyExists() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The name specified already exists";
    }
};


#endif //HOUSE_SIMULATOR_NAMEALREADYEXISTS_H
