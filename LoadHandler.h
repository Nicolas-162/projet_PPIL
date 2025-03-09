#ifndef LOADHANDLER_H
#define LOADHANDLER_H

#include "FormeGeometrique.h"
#include <memory>
#include <string>

class LoadHandler {
protected:
    LoadHandler* nextHandler;

public:
    LoadHandler() : nextHandler(nullptr) {}
    virtual ~LoadHandler() {}

    void setNextHandler(LoadHandler* next) {
        nextHandler = next;
    }

    virtual std::shared_ptr<FormeGeometrique> handle(const std::string& line) {
        if (nextHandler) {
            return nextHandler->handle(line);
        }
        return nullptr;
    }
};

#endif // LOADHANDLER_H