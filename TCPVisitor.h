#ifndef TCPVISITOR_H
#define TCPVISITOR_H

#include "Visitor.h"
#include "TCPClient.h"
#include "FormeGeometrique.h"

class TCPVisitor : public Visitor {
private:
    TCPClient client;

public:
    TCPVisitor(const std::string& ip, int port) : client(ip, port) {}

    void visit(FormeGeometrique& forme) override {
        client.send(forme.toString());
    }
};

#endif // TCPVISITOR_H