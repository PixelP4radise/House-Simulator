//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOMNOTFOUND_H
#define HOUSE_SIMULATOR_ROOMNOTFOUND_H

#include <exception>

class roomNotFound : public std::exception {
public:
    roomNotFound() noexcept = default;

    ~roomNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The room specified wasn't found.";
    }
};


#endif //HOUSE_SIMULATOR_ROOMNOTFOUND_H
