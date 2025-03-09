#include "TCPClient.h"
#include <iostream>

TCPClient::TCPClient(const std::string& ip, int port) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr(ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    connect(sock, (struct sockaddr*)&server, sizeof(server));
}

TCPClient::~TCPClient() {
    closesocket(sock);
    WSACleanup();
}

void TCPClient::send(const std::string& message) {
    ::send(sock, message.c_str(), message.size(), 0);
}

std::string TCPClient::receive() {
    char buffer[1024];
    int size = recv(sock, buffer, sizeof(buffer), 0);
    return std::string(buffer, size);
}