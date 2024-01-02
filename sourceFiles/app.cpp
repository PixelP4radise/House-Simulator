//
// Created by guilh on 01/01/2024.
//
#include <iostream>
#include "../headerFiles/app.h"

using namespace term;

void launchApp(term::Terminal &t) {
    std::unique_ptr<house> housePtr{};

    Window console = t.create_window(37, 0, 231, 3,
                                     true); // the commands will be input here

    Window consoleLog = t.create_window(0, 0, 35, 63, true);

    Window zonaHabitaculos = t.create_window(37, 4, 231, 59, true);

    std::string command{};

    do {
        console.clear();
        console >> command;
        try {
            launchCommand(command, housePtr, consoleLog);
        } catch (const commandNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const fileNotOpened &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const processorNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const roomNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const std::bad_alloc &ex) {
            consoleLog << "Couldn't create Item.\n";
        } catch (const positionOcuppied &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const invalidPosition &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const unknowRule &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const ruleNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const outOfRangeProperty &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const invalidDeviceType &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const deviceNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const acessError &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const nameAlreadyExists &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const nameNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const invalidSensorType &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const sensorNotFound &ex) {
            consoleLog << ex.what() << '\n';
        } catch (const houseNotCreated &ex) {
            consoleLog << ex.what() << '\n';
        }
    } while (command != "exit");
}

void launchCommand(std::string &command, std::unique_ptr<house> &housePtr, Window &consoleLog) {
    std::istringstream iss(command);
    std::vector<std::string> argumentsVector;

    std::string argument;

    unsigned int nArgumentos{};

    while (iss >> argument) {
        argumentsVector.push_back(argument);
        nArgumentos++;
    }
    if (argumentsVector.at(0) == "hnew" and nArgumentos == 3) {
        housePtr = std::make_unique<house>(std::stoi(argumentsVector.at(1)), std::stoi(argumentsVector.at(2)));
        consoleLog << "A simulation has been started\n";
    } else if (argumentsVector.at(0) == "hrem" and nArgumentos == 1) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr.reset();
        consoleLog << "The simulation has been erased\n";
    } else if (argumentsVector.at(0) == "next" and nArgumentos == 1) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->carryOut();
        consoleLog << "Forwarded an instant\n";
    } else if (argumentsVector.at(0) == "advance" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        int nIterations = std::stoi(argumentsVector.at(1));
        for (int i = 0; i < nIterations; ++i)
            housePtr->carryOut();
        consoleLog << "Forwarded " + std::to_string(nIterations) + " instants.\n";
    } else if (argumentsVector.at(0) == "znew" and nArgumentos == 3) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->newRoom(std::stoi(argumentsVector.at(1)), std::stoi(argumentsVector.at(2)));
        consoleLog << "A room has been created\n";
    } else if (argumentsVector.at(0) == "zrem" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->deleteRoom(argumentsVector.at(1));
        consoleLog << "Room with id: " + argumentsVector.at(1) + " was deleted.\n";
    } else if (argumentsVector.at(0) == "zlist" and nArgumentos == 1) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        consoleLog << housePtr->describeHouse();
    } else if (argumentsVector.at(0) == "zcomp" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        consoleLog << housePtr->describeRoom(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "zprops" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        consoleLog << housePtr->showPropertysOfRoom(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "pmod" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->changePropertyOfRoom(argumentsVector.at(1), argumentsVector.at(2), std::stoi(argumentsVector.at(3)));
        consoleLog << "Room " + argumentsVector.at(1) + " Property " + argumentsVector.at(2) + " was changed to " +
                      argumentsVector.at(3) + '\n';
    } else if (argumentsVector.at(0) == "cnew" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->newComponent(argumentsVector.at(1), argumentsVector.at(2)[0], argumentsVector.at(3));
        consoleLog << "A new component has been added to " + argumentsVector.at(1) + '\n';
    } else if (argumentsVector.at(0) == "crem" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->removeComponent(argumentsVector.at(1), argumentsVector.at(2)[0], argumentsVector.at(3));
        consoleLog << "Component with ID: " + argumentsVector.at(3) + " has been removed from room: " +
                      argumentsVector.at(1) +
                      '\n';
    } else if (argumentsVector.at(0) == "rnew" and nArgumentos == 6) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->addRule(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(4), argumentsVector.at(3),
                          std::stoi(argumentsVector.at(5)));
        consoleLog << "Added rule: " + argumentsVector.at(4) + " to processor: " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "rnew" and nArgumentos == 7) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->addRule(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(4), argumentsVector.at(3),
                          std::stoi(argumentsVector.at(5)), std::stoi(argumentsVector.at(6)));
        consoleLog << "Added rule: " + argumentsVector.at(4) + " to processor: " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "pchange" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->changeCommandFromProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog
                << "Changed command from processor: " + argumentsVector.at(2) + " to " + argumentsVector.at(3) + '\n';
    } else if (argumentsVector.at(0) == "rlist" and nArgumentos == 3) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        consoleLog << housePtr->showRulesFrom(argumentsVector.at(1), argumentsVector.at(2));
    } else if (argumentsVector.at(0) == "rrem" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->removeRuleFrom(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog << "Rule: " + argumentsVector.at(3) + " removed from: " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "asoc" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->associateDeviceToProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog << "Device: " + argumentsVector.at(3) + " associated to " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "disa" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->disaDeviceFromProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog << "Device: " + argumentsVector.at(3) + " dissassociated from " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "dcom" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->sendCommandToDevice(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog << "Command: " + argumentsVector.at(3) + " sent to device: " + argumentsVector.at(2) + '\n';
    } else if (argumentsVector.at(0) == "psave" and nArgumentos == 4) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->saveProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
        consoleLog << "Processor: " + argumentsVector.at(2) + " saved under name: " + argumentsVector.at(3) + '\n';
    } else if (argumentsVector.at(0) == "prestore" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->restoreProcessor(argumentsVector.at(1));
        consoleLog << "Restored Processor with name: " + argumentsVector.at(1) + '\n';
    } else if (argumentsVector.at(0) == "prem" and nArgumentos == 2) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        housePtr->removeProcessorFromMemory(argumentsVector.at(1));
        consoleLog << "Processor with name: " + argumentsVector.at(1) + " removed from memory.";
    } else if (argumentsVector.at(0) == "plist" and nArgumentos == 1) {
        if (housePtr == nullptr)
            throw houseNotCreated();
        consoleLog << housePtr->showProcessorsFromMemory();
    } else if (argumentsVector.at(0) == "exec" and nArgumentos == 2) {
        execFicheiro(argumentsVector.at(1), housePtr, consoleLog);
        consoleLog << "Ficheiro executado.\n";
    } else {
        throw commandNotFound();
    }
}

void execFicheiro(const std::string &name, std::unique_ptr<house> &housePtr, Window &consoleLog) {
    std::string command{};
    std::ifstream File(name);
    if (!File.is_open()) {
        throw fileNotOpened();
    }
    while (std::getline(File, command))
        launchCommand(command, housePtr, consoleLog);
    File.close();
}