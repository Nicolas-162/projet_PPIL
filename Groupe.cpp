#include "Groupe.h"

// Constructeur
Groupe::Groupe(const std::string& couleur) : FormeGeometrique(couleur) {}

// Ajouter une forme au groupe
void Groupe::ajouterForme(const std::shared_ptr<FormeGeometrique>& forme) {
    formes.push_back(forme);
}

// Obtenir les formes du groupe
std::vector<std::shared_ptr<FormeGeometrique>> Groupe::getFormes() const {
    return formes;
}

// Conversion en string
std::string Groupe::toString() const {
    std::ostringstream os;
    os << "Groupe [Couleur: " << couleur << ", Formes: ";
    for (const auto& forme : formes) {
        os << forme->toString() << " ";
    }
    os << "]";
    return os.str();
}