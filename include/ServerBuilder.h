#ifndef SERVER_BUILDER_H
#define SERVER_BUILDER_H

#include "Types.h"
#include "Server.h"

#include <string>
#include <string_view>

class ServerBuilder
{
private:
    std::string ip_address;
    uint16_t port;
    Types::SocketDomain ip_type;
    Types::SocketCommunication socket_communication;
    std::size_t number_of_connections;

public:
    static constexpr std::string_view DEFAULT_IP_ADDRESS = "127.0.0.1";
    static constexpr uint16_t DEFAULT_PORT = 15000;
    static constexpr Types::SocketDomain DEFAULT_IP_TYPE = Types::SocketDomain::IPv4;
    static constexpr Types::SocketCommunication DEFAULT_SOCKET_COMMUNICATION = Types::SocketCommunication::TCP;
    static constexpr std::size_t DEFAULT_INITIAL_NUMBER_OF_CONNECTIONS = 1;

    ServerBuilder();

    ServerBuilder& withIpAddress(const std::string& ip_address);
    ServerBuilder& withPort(uint16_t port);
    ServerBuilder& withIpType(Types::SocketDomain ip_type);
    ServerBuilder& withSocketCommunication(Types::SocketCommunication socket_communication);
    ServerBuilder& withInitialNumberOfConnections(std::size_t number_of_connections);

    Server build();
};

#endif