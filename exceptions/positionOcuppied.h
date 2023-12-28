//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_POSITIONOCUPPIED_H
#define HOUSE_SIMULATOR_POSITIONOCUPPIED_H

#include <exception>

class positionOcuppied : public std::exception {
public:
    positionOcuppied() noexcept = default;

    ~positionOcuppied() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "You can't create a room in that position because it's already occupied.";
    }
};


#endif //HOUSE_SIMULATOR_POSITIONOCUPPIED_H
