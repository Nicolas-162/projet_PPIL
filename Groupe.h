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

    double area() const override {
        double totalArea = 0.0;
        for (const auto& forme : formes) {
            totalArea += forme->area();
        }
        return totalArea;
    }

    void translater(double dx, double dy) override {
        for (auto& forme : formes) {
            forme->translater(dx, dy);
        }
    }

    void homothetie(double cx, double cy, double rapport) override {
        for (auto& forme : formes) {
            forme->homothetie(cx, cy, rapport);
        }
    }

    void rotation(double cx, double cy, double angle) override {
        for (auto& forme : formes) {
            forme->rotation(cx, cy, angle);
        }
    }

    void accept(Visitor& visitor) override {
        for (auto& forme : formes) {
            forme->setCouleur(couleur); // Apply group color to each shape
            forme->accept(visitor);
        }
    }

    operator std::string() const override {
        return toString();
    }
};

#endif // GROUPE_H