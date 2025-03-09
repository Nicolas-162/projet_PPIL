#include "Groupe.h"
#include "FormeGeometrique.h"
#include "TCPVisitor.h"
#include "WinsockInitializer.h"
#include "SaveVisitor.h"
#include "SimpleShapeLoadHandler.h"
#include <iostream>
#include <memory>
#include <fstream>

class FormeGeometriqueSimple : public FormeGeometrique {
public:
    FormeGeometriqueSimple(const std::string& couleur, double x, double y) : FormeGeometrique(couleur), x(x), y(y) {}

    std::string toString() const override {
        return "FormeGeometriqueSimple " + couleur;
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

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

private:
    double x, y;
};

int main() {
    // Ensure Winsock is initialized
    WinsockInitializer::getInstance();

    // Create a group with a specific color
    Groupe groupe("red");

    // Create some geometric shapes
    auto forme1 = std::make_shared<FormeGeometriqueSimple>("blue", 0.574299, 4.33274);
    auto forme2 = std::make_shared<FormeGeometriqueSimple>("green", 0.89098, 4.17736);

    // Add shapes to the group
    groupe.ajouterForme(forme1);
    groupe.ajouterForme(forme2);

    // Create a TCP visitor
    TCPVisitor visitor("127.0.0.1", 12345);

    // Use the visitor to draw the shapes
    groupe.accept(visitor);

    // Save the shapes to a file
    std::ofstream outFile("shapes.txt");
    SaveVisitor saveVisitor(outFile);
    groupe.accept(saveVisitor);
    outFile.close();

    // Load the shapes from a file
    std::ifstream inFile("shapes.txt");
    std::string line;
    SimpleShapeLoadHandler simpleHandler;
    while (std::getline(inFile, line)) {
        auto shape = simpleHandler.handle(line);
        if (shape) {
            groupe.ajouterForme(shape);
        }
    }
    inFile.close();

    return 0;
}