#ifndef POLYGONE_H
#define POLYGONE_H

#include "FormeGeometrique.h"
#include "Point2D.h"
#include <vector>

class Polygone : public FormeGeometrique {
private:
    std::vector<Point2D> sommets;

public:
    Polygone(const std::vector<Point2D>& sommets, const std::string& couleur)
        : FormeGeometrique(couleur), sommets(sommets) {}

    std::vector<Point2D> getSommets() const { return sommets; }

    std::string toString() const override {
        std::ostringstream os;
        os << "Polygone [Sommets: ";
        for (const auto& sommet : sommets) {
            os << sommet.toString() << " ";
        }
        os << ", Couleur: " << couleur << "]";
        return os.str();
    }
};

#endif // POLYGONE_H