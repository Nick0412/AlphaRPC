#ifndef SOCKET_INTERNET_ADDRESS
#define SOCKET_INTERNET_ADDRESS

#include <arpa/inet.h>

class SocketInternalAddress
{
private:
    sockaddr_in address;
};

#endif