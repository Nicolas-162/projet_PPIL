#ifndef WINSOCKINITIALIZER_H
#define WINSOCKINITIALIZER_H

#include <winsock2.h>

class WinsockInitializer {
private:
    WinsockInitializer() {
        WSADATA wsa;
        WSAStartup(MAKEWORD(2, 2), &wsa);
    }

    ~WinsockInitializer() {
        WSACleanup();
    }

public:
    static WinsockInitializer& getInstance() {
        static WinsockInitializer instance;
        return instance;
    }

    WinsockInitializer(const WinsockInitializer&) = delete;
    WinsockInitializer& operator=(const WinsockInitializer&) = delete;
};

#endif // WINSOCKINITIALIZER_H