//
// Created by guilh on 29/12/2023.
//

#ifndef HOUSE_SIMULATOR_PROCESSORNOTFOUND_H
#define HOUSE_SIMULATOR_PROCESSORNOTFOUND_H

#include <exception>

class processorNotFound : public std::exception {
public:
    processorNotFound() noexcept = default;

    ~processorNotFound() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The processor specified wasn't found.";
    }
};


#endif //HOUSE_SIMULATOR_PROCESSORNOTFOUND_H
