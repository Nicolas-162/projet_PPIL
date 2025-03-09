#ifndef FORMEGEOMETRIQUESIMPLE_H
#define FORMEGEOMETRIQUESIMPLE_H

#include "FormeGeometrique.h"
#include <sstream>

class FormeGeometriqueSimple : public FormeGeometrique {
private:
    double x, y;

public:
    FormeGeometriqueSimple(const std::string& couleur, double x, double y)
        : FormeGeometrique(couleur), x(x), y(y) {}

    std::string toString() const override {
        std::ostringstream oss;
        oss << "FormeGeometriqueSimple " << couleur << " (" << x << ", " << y << ")";
        return oss.str();
    }

    double area() const override {
        // Assuming this is a point, the area is zero.
        return 0.0;
    }

    void translater(double dx, double dy) override {
        x += dx;
        y += dy;
    }

    void homothetie(double cx, double cy, double rapport) override {
        x = cx + rapport * (x - cx);
        y = cy + rapport * (y - cy);
    }

    void rotation(double cx, double cy, double angle) override {
        double newX = cx + (x - cx) * cos(angle) - (y - cy) * sin(angle);
        double newY = cy + (x - cx) * sin(angle) + (y - cy) * cos(angle);
        x = newX;
        y = newY;
    }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    operator std::string() const override {
        return toString();
    }
};

#endif // FORMEGEOMETRIQUESIMPLE_H