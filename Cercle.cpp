#include "Cercle.h"

// Constructeurs
Cercle::Cercle(const Point2D& centre, double rayon, const std::string& couleur)
    : FormeGeometrique(couleur), centre(centre), rayon(rayon) {}

// Accesseurs
Point2D Cercle::getCentre() const { return centre; }
double Cercle::getRayon() const { return rayon; }

// Conversion en string
std::string Cercle::toString() const {
    std::ostringstream os;
    os << "Cercle [Centre: " << centre.toString() << ", Rayon: " << rayon 
       << ", Couleur: " << couleur << "]";
    return os.str();
}