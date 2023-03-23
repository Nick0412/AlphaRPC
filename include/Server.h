#ifndef SERVER_H
#define SERVER_H

#include "DataChannel.h"
#include "Types.h"

#include <string>
#include <vector>

class Server
{
private:
    Types::SocketType server_socket;
    std::vector<DataChannel> connected_sockets;
    std::string ip_address;
    uint16_t port;
    Types::SocketDomain ip_type;
    Types::SocketCommunication socket_communication;

public:
    Server() = delete;

    Server(const std::string& ip_address, uint16_t port, Types::SocketDomain ip_type, Types::SocketCommunication socket_communication, size_t initial_connection_count);
};

#endif