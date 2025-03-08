#include "Polygone.h"

// Constructeurs
Polygone::Polygone(const std::vector<Point2D>& sommets, const std::string& couleur)
    : FormeGeometrique(couleur), sommets(sommets) {}

// Accesseurs
std::vector<Point2D> Polygone::getSommets() const { return sommets; }

// Conversion en string
std::string Polygone::toString() const {
    std::ostringstream os;
    os << "Polygone [Sommets: ";
    for (const auto& sommet : sommets) {
        os << sommet.toString() << " ";
    }
    os << ", Couleur: " << couleur << "]";
    return os.str();
}