#ifndef VISITOR_H
#define VISITOR_H

class FormeGeometrique;

class Visitor {
public:
    virtual void visit(FormeGeometrique& forme) = 0;
};

#endif // VISITOR_H