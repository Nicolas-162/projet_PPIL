#ifndef GROUPE_H
#define GROUPE_H

#include "FormeGeometrique.h"
#include <vector>
#include <memory>
#include <sstream>

class Groupe : public FormeGeometrique {
private:
    std::vector<std::shared_ptr<FormeGeometrique>> formes;

public:
    Groupe(const std::string& couleur) : FormeGeometrique(couleur) {}

    void ajouterForme(const std::shared_ptr<FormeGeometrique>& forme) {
        formes.push_back(forme);
    }

    std::vector<std::shared_ptr<FormeGeometrique>> getFormes() const {
        return formes;
    }

    std::string toString() const override {
        std::ostringstream os;
        os << "Groupe [Couleur: " << couleur << ", Formes: ";
        for (const auto& forme : formes) {
            os << forme->toString() << " ";
        }
        os << "]";
        return os.str();
    }
};

#endif // GROUPE_H