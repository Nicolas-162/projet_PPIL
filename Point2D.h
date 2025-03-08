#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>
#include <sstream>

class Point2D {
private:
    double x, y;

public:
    // Constructeurs
    Point2D(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // Accesseurs
    double getX() const { return x; }
    double getY() const { return y; }
    
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }

    // Distance entre deux points
    double distance(const Point2D& autre) const {
        return std::sqrt(std::pow(autre.x - x, 2) + std::pow(autre.y - y, 2));
    }

    // Opérateur de conversion en string
    std::string toString() const {
        std::ostringstream os;
        os << "(" << x << ", " << y << ")";
        return os.str();
    }

    // Surcharge des opérateurs
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p) {
        os << p.toString();
        return os;
    }

    Point2D operator+(const Point2D& p) const {
        return Point2D(x + p.x, y + p.y);
    }

    Point2D operator-(const Point2D& p) const {
        return Point2D(x - p.x, y - p.y);
    }

    Point2D operator*(double scalaire) const {
        return Point2D(x * scalaire, y * scalaire);
    }

    bool operator==(const Point2D& p) const {
        return (x == p.x) && (y == p.y);
    }
};

#endif // POINT2D_H
