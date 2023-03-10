#include "Networking/ServerSocket.h"

ServerSocket::ServerSocket(const Endpoint& endpoint)
{
    socket_pointer = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(endpoint.getPort());
    server_address.sin_addr.s_addr = inet_addr(endpoint.getIpAddress().c_str());

    auto casted_socket_address = reinterpret_cast<const sockaddr*>(&server_address);
    auto socket_address_size = sizeof(server_address);
    bind(socket_pointer, casted_socket_address, socket_address_size); 
}

ServerSocket::~ServerSocket()
{
    close(socket_pointer);
}

void ServerSocket::listenForConnections()
{
    listen(socket_pointer, 1);
}

DataSocket ServerSocket::acceptConnections()
{
    struct sockaddr_in client_address;
    auto recasted_client_address = reinterpret_cast<sockaddr*>(&client_address);
    socklen_t address_size;

    int connected_socket = accept(socket_pointer, recasted_client_address, &address_size);

    return DataSocket(connected_socket);
}

