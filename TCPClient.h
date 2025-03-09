#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <winsock2.h>
#include <string>

class TCPClient {
private:
    SOCKET sock;
    sockaddr_in server;

public:
    TCPClient(const std::string& ip, int port);
    ~TCPClient();
    void send(const std::string& message);
    std::string receive();
};

#endif // TCPCLIENT_H