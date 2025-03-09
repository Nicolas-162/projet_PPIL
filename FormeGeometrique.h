#ifndef FORMEGEOMETRIQUE_H
#define FORMEGEOMETRIQUE_H

#include <string>
#include <stdexcept>
#include <set>
#include "Visitor.h"

class FormeGeometrique {
protected:
    std::string couleur;

    void validateCouleur(const std::string& couleur) {
        static const std::set<std::string> validColors = {"black", "blue", "red", "green", "yellow", "cyan"};
        if (validColors.find(couleur) == validColors.end()) {
            throw std::invalid_argument("Invalid color: " + couleur);
        }
    }

public:
    FormeGeometrique(const std::string& couleur) {
        validateCouleur(couleur);
        this->couleur = couleur;
    }
    virtual ~FormeGeometrique() {}

    std::string getCouleur() const { return couleur; }
    void setCouleur(const std::string& couleur) {
        validateCouleur(couleur);
        this->couleur = couleur;
    }

    virtual std::string toString() const = 0;
    virtual double area() const = 0;

    // Transformation methods
    virtual void translater(double dx, double dy) = 0;
    virtual void homothetie(double cx, double cy, double rapport) = 0;
    virtual void rotation(double cx, double cy, double angle) = 0;

    // Accept method for Visitor
    virtual void accept(Visitor& visitor) = 0;

    // String conversion operator
    virtual operator std::string() const {
        return toString();
    }
};

#endif // FORMEGEOMETRIQUE_H