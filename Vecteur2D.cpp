#include "Vecteur2D.h"

// Constructeurs
Vecteur2D::Vecteur2D(const Point2D& p1, const Point2D& p2) 
    : origine(p1), direction(p2) {}

// Accesseurs
Point2D Vecteur2D::getOrigine() const { return origine; }
Point2D Vecteur2D::getDirection() const { return direction; }

void Vecteur2D::setOrigine(const Point2D& p) { origine = p; }
void Vecteur2D::setDirection(const Point2D& p) { direction = p; }

// Longueur du vecteur
double Vecteur2D::norme() const {
    return origine.distance(direction);
}

// Calcul du vecteur résultant
Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const {
    return Vecteur2D(origine, Point2D(direction.getX() + v.direction.getX(),
                                      direction.getY() + v.direction.getY()));
}

// Multiplication par un scalaire
Vecteur2D Vecteur2D::operator*(double scalaire) const {
    return Vecteur2D(origine, Point2D(direction.getX() * scalaire,
                                      direction.getY() * scalaire));
}

// Produit scalaire
double Vecteur2D::produitScalaire(const Vecteur2D& v) const {
    double dx1 = direction.getX() - origine.getX();
    double dy1 = direction.getY() - origine.getY();
    double dx2 = v.direction.getX() - v.origine.getX();
    double dy2 = v.direction.getY() - v.origine.getY();
    return dx1 * dx2 + dy1 * dy2;
}

// Rotation du vecteur autour de l'origine d'un angle (en radians)
Vecteur2D Vecteur2D::rotation(double angle) const {
    double dx = direction.getX() - origine.getX();
    double dy = direction.getY() - origine.getY();

    double newX = dx * cos(angle) - dy * sin(angle);
    double newY = dx * sin(angle) + dy * cos(angle);

    return Vecteur2D(origine, Point2D(origine.getX() + newX, origine.getY() + newY));
}

// Conversion en string
std::string Vecteur2D::toString() const {
    std::ostringstream os;
    os << "[Origine: " << origine.toString() 
       << ", Direction: " << direction.toString() << "]";
    return os.str();
}

// Affichage
std::ostream& operator<<(std::ostream& os, const Vecteur2D& v) {
    os << v.toString();
    return os;
}