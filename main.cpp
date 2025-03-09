#include "Groupe.h"
#include "FormeGeometrique.h"
#include "FormeGeometriqueSimple.h"
#include "TCPVisitor.h"
#include "WinsockInitializer.h"
#include "SaveVisitor.h"
#include "SimpleShapeLoadHandler.h"
#include <iostream>
#include <memory>
#include <fstream>

int main() {
    // Assurez-vous que Winsock est initialisé
    WinsockInitializer::getInstance();

    // Créez un groupe avec une couleur spécifique
    Groupe groupe("red");

    // Créez quelques formes géométriques
    auto forme1 = std::make_shared<FormeGeometriqueSimple>("blue", 0.574299, 4.33274);
    auto forme2 = std::make_shared<FormeGeometriqueSimple>("green", 0.89098, 4.17736);

    // Ajoutez les formes au groupe
    groupe.ajouterForme(forme1);
    groupe.ajouterForme(forme2);

    // Affichez les détails du groupe initial
    std::cout << "Groupe initial : " << std::string(groupe) << std::endl;

    // Appliquez des transformations
    groupe.translater(1.0, 1.0);
    groupe.homothetie(0.0, 0.0, 2.0);
    groupe.rotation(0.0, 0.0, 3.14159 / 4);

    // Affichez les détails du groupe après les transformations
    std::cout << "Groupe après transformations : " << std::string(groupe) << std::endl;

    // Créez un visiteur TCP pour dessiner les formes
    TCPVisitor visitor("127.0.0.1", 12345);
    groupe.accept(visitor);

    // Enregistrez les formes dans un fichier
    std::ofstream outFile("shapes.txt");
    SaveVisitor saveVisitor(outFile);
    groupe.accept(saveVisitor);
    outFile.close();

    // Créez un nouveau groupe pour charger les formes à partir du fichier
    Groupe loadedGroupe("red");

    // Chargez les formes à partir du fichier
    std::ifstream inFile("shapes.txt");
    std::string line;
    SimpleShapeLoadHandler simpleHandler;
    while (std::getline(inFile, line)) {
        auto shape = simpleHandler.handle(line);
        if (shape) {
            loadedGroupe.ajouterForme(shape);
        }
    }
    inFile.close();

    // Affichez les détails du groupe chargé
    std::cout << "Groupe chargé : " << std::string(loadedGroupe) << std::endl;

    // Calculez et affichez la surface du groupe chargé
    std::cout << "Surface totale du groupe chargé : " << loadedGroupe.area() << std::endl;

    return 0;
}