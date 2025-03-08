#ifndef CERCLE_H
#define CERCLE_H

#include "FormeGeometrique.h"
#include "Point2D.h"

class Cercle : public FormeGeometrique {
private:
    Point2D centre;
    double rayon;

public:
    Cercle(const Point2D& centre, double rayon, const std::string& couleur)
        : FormeGeometrique(couleur), centre(centre), rayon(rayon) {}

    Point2D getCentre() const { return centre; }
    double getRayon() const { return rayon; }

    std::string toString() const override {
        std::ostringstream os;
        os << "Cercle [Centre: " << centre.toString() << ", Rayon: " << rayon 
           << ", Couleur: " << couleur << "]";
        return os.str();
    }
};

#endif // CERCLE_H