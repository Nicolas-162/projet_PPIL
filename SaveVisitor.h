#ifndef SAVEVISITOR_H
#define SAVEVISITOR_H

#include "Visitor.h"
#include <fstream>

class SaveVisitor : public Visitor {
private:
    std::ofstream& outFile;

public:
    SaveVisitor(std::ofstream& out) : outFile(out) {}

    void visit(FormeGeometrique& forme) override {
        outFile << forme.toString() << std::endl;
    }
};

#endif // SAVEVISITOR_H