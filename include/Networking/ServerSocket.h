#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include "Endpoint.h"
#include "Types.h"
#include "DataSocket.h"

#include <arpa/inet.h>
#include <sys/socket.h>

class ServerSocket
{
private:
    int socket_pointer;
    struct sockaddr_in server_address;

public:
    ServerSocket(const Endpoint& endpoint);
    ~ServerSocket();

    void listenForConnections();
    // Blocking call.
    DataSocket acceptConnections();
};

#endif