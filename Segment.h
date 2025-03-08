#ifndef SEGMENT_H
#define SEGMENT_H

#include "FormeGeometrique.h"
#include "Point2D.h"

class Segment : public FormeGeometrique {
private:
    Point2D p1, p2;

public:
    Segment(const Point2D& p1, const Point2D& p2, const std::string& couleur)
        : FormeGeometrique(couleur), p1(p1), p2(p2) {}

    Point2D getP1() const { return p1; }
    Point2D getP2() const { return p2; }

    std::string toString() const override {
        std::ostringstream os;
        os << "Segment [P1: " << p1.toString() << ", P2: " << p2.toString() 
           << ", Couleur: " << couleur << "]";
        return os.str();
    }
};

#endif // SEGMENT_H