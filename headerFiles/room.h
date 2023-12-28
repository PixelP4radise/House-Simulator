//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOM_H
#define HOUSE_SIMULATOR_ROOM_H

#include "houseElements.h"

class room : public houseElements {
private:
    unsigned int nLines, nCollums;
public:
    room(unsigned int nLines, unsigned int nCollumns);

    [[nodiscard]]
    unsigned int getNLines() const;

    [[nodiscard]]
    unsigned int getNCollums() const;

    [[nodiscard]]
    std::string getId() const override;
};


#endif //HOUSE_SIMULATOR_ROOM_H
