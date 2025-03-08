#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "FormeGeometrique.h"
#include "Point2D.h"

class Triangle : public FormeGeometrique {
private:
    Point2D p1, p2, p3;

public:
    Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3, const std::string& couleur)
        : FormeGeometrique(couleur), p1(p1), p2(p2), p3(p3) {}

    Point2D getP1() const { return p1; }
    Point2D getP2() const { return p2; }
    Point2D getP3() const { return p3; }

    std::string toString() const override {
        std::ostringstream os;
        os << "Triangle [P1: " << p1.toString() << ", P2: " << p2.toString() 
           << ", P3: " << p3.toString() << ", Couleur: " << couleur << "]";
        return os.str();
    }
};

#endif // TRIANGLE_H