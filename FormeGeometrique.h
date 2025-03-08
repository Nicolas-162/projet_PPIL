#ifndef FORMEGEOMETRIQUE_H
#define FORMEGEOMETRIQUE_H

#include <string>
#include <stdexcept>
#include <set>

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
};

#endif // FORMEGEOMETRIQUE_H