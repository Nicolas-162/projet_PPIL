#include "Segment.h"

// Constructeurs
Segment::Segment(const Point2D& p1, const Point2D& p2, const std::string& couleur)
    : FormeGeometrique(couleur), p1(p1), p2(p2) {}

// Accesseurs
Point2D Segment::getP1() const { return p1; }
Point2D Segment::getP2() const { return p2; }

// Conversion en string
std::string Segment::toString() const {
    std::ostringstream os;
    os << "Segment [P1: " << p1.toString() << ", P2: " << p2.toString() 
       << ", Couleur: " << couleur << "]";
    return os.str();
}