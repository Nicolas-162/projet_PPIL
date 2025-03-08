#include "Triangle.h"

// Constructeurs
Triangle::Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3, const std::string& couleur)
    : FormeGeometrique(couleur), p1(p1), p2(p2), p3(p3) {}

// Accesseurs
Point2D Triangle::getP1() const { return p1; }
Point2D Triangle::getP2() const { return p2; }
Point2D Triangle::getP3() const { return p3; }

// Conversion en string
std::string Triangle::toString() const {
    std::ostringstream os;
    os << "Triangle [P1: " << p1.toString() << ", P2: " << p2.toString() 
       << ", P3: " << p3.toString() << ", Couleur: " << couleur << "]";
    return os.str();
}