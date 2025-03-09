#include "Groupe.h"
#include "FormeGeometrique.h"
#include <iostream>
#include <memory>

class FormeGeometriqueSimple : public FormeGeometrique {
public:
    FormeGeometriqueSimple(const std::string& couleur) : FormeGeometrique(couleur) {}

    std::string toString() const override {
        return "FormeGeometriqueSimple [Couleur: " + couleur + "]";
    }

    void translater(double dx, double dy) override {
        // Implement translation logic here
    }

    void homothetie(double cx, double cy, double rapport) override {
        // Implement homothety logic here
    }

    void rotation(double cx, double cy, double angle) override {
        // Implement rotation logic here
    }
};

int main() {
    // Create a group with a specific color
    Groupe groupe("red");

    // Create some geometric shapes
    auto forme1 = std::make_shared<FormeGeometriqueSimple>("blue");
    auto forme2 = std::make_shared<FormeGeometriqueSimple>("green");

    // Add shapes to the group
    groupe.ajouterForme(forme1);
    groupe.ajouterForme(forme2);

    // Print the group details
    std::cout << groupe.toString() << std::endl;

    // Apply transformations
    groupe.translater(10, 20);
    groupe.homothetie(0, 0, 2);
    groupe.rotation(0, 0, 3.14159 / 4);

    // Print the group details after transformations
    std::cout << groupe.toString() << std::endl;

    return 0;
}