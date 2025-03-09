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
};

int main() {
    // Create a group with a specific color
    Groupe groupe("Rouge");

    // Create some geometric shapes
    auto forme1 = std::make_shared<FormeGeometriqueSimple>("Bleu");
    auto forme2 = std::make_shared<FormeGeometriqueSimple>("Vert");

    // Add shapes to the group
    groupe.ajouterForme(forme1);
    groupe.ajouterForme(forme2);

    // Print the group details
    std::cout << groupe.toString() << std::endl;

    return 0;
}