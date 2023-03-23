#include "ServerBuilder.h"

ServerBuilder::ServerBuilder()
: ip_address{ServerBuilder::DEFAULT_IP_ADDRESS},
  port{ServerBuilder::DEFAULT_PORT},
  ip_type{ServerBuilder::DEFAULT_IP_TYPE},
  socket_communication{ServerBuilder::DEFAULT_SOCKET_COMMUNICATION},
  number_of_connections{DEFAULT_INITIAL_NUMBER_OF_CONNECTIONS}
{

}

ServerBuilder& ServerBuilder::withIpAddress(const std::string& ip_address)
{
    this->ip_address = ip_address;
    return *this;
}

ServerBuilder& ServerBuilder::withPort(uint16_t port)
{
    this->port = port;
    return *this;
}

ServerBuilder& ServerBuilder::withIpType(Types::SocketDomain ip_type)
{
    this->ip_type = ip_type;
    return *this;
}

ServerBuilder& ServerBuilder::withSocketCommunication(Types::SocketCommunication socket_communication)
{
    this->socket_communication = socket_communication;
    return *this;
}

ServerBuilder& ServerBuilder::withInitialNumberOfConnections(std::size_t number_of_connections)
{
    this->number_of_connections = number_of_connections;
    return *this;
}

Server ServerBuilder::build()
{
    return Server(ip_address, port, ip_type, socket_communication, number_of_connections);
}