//
// Created by guilh on 01/01/2024.
//

#ifndef HOUSE_SIMULATOR_FILENOTOPENED_H
#define HOUSE_SIMULATOR_FILENOTOPENED_H


#include <exception>

class fileNotOpened : public std::exception {
public:
    fileNotOpened() noexcept = default;

    ~fileNotOpened() override = default;

    [[nodiscard]]
    const char *what() const noexcept override {
        return "The device specified wasn't found.";
    }
};

#endif //HOUSE_SIMULATOR_FILENOTOPENED_H
