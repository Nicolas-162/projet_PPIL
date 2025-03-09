#ifndef SIMPLESHAPELOADHANDLER_H
#define SIMPLESHAPELOADHANDLER_H

#include "LoadHandler.h"
#include "FormeGeometriqueSimple.h"
#include <sstream>

class SimpleShapeLoadHandler : public LoadHandler {
public:
    std::shared_ptr<FormeGeometrique> handle(const std::string& line) override {
        if (line.find("FormeGeometriqueSimple") != std::string::npos) {
            std::istringstream iss(line);
            std::string type, couleur;
            double x, y;
            iss >> type >> couleur >> x >> y;
            return std::make_shared<FormeGeometriqueSimple>(couleur, x, y);
        }
        return LoadHandler::handle(line);
    }
};

#endif // SIMPLESHAPELOADHANDLER_H