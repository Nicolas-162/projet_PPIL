#include "Point2D.h"

// Constructeurs
Point2D::Point2D(double _x, double _y) : x(_x), y(_y) {}

// Accesseurs
double Point2D::getX() const { return x; }
double Point2D::getY() const { return y; }

void Point2D::setX(double _x) { x = _x; }
void Point2D::setY(double _y) { y = _y; }

// Distance entre deux points
double Point2D::distance(const Point2D& autre) const {
    return std::sqrt(std::pow(autre.x - x, 2) + std::pow(autre.y - y, 2));
}

// Opérateur de conversion en string
std::string Point2D::toString() const {
    std::ostringstream os;
    os << "(" << x << ", " << y << ")";
    return os.str();
}

// Surcharge des opérateurs
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << p.toString();
    return os;
}

Point2D Point2D::operator+(const Point2D& p) const {
    return Point2D(x + p.x, y + p.y);
}

Point2D Point2D::operator-(const Point2D& p) const {
    return Point2D(x - p.x, y - p.y);
}

Point2D Point2D::operator*(double scalaire) const {
    return Point2D(x * scalaire, y * scalaire);
}

bool Point2D::operator==(const Point2D& p) const {
    return (x == p.x) && (y == p.y);
}