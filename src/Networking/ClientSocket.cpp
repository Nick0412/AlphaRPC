#include "Networking/ClientSocket.h"

ClientSocket::ClientSocket(const Endpoint& endpoint)
{
    socket_pointer = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(endpoint.getPort());
    server_address.sin_addr.s_addr = inet_addr(endpoint.getIpAddress().c_str());
}

void ClientSocket::connectToServer()
{
    auto casted_socket_address = reinterpret_cast<const sockaddr*>(&server_address);
    auto socket_address_size = sizeof(server_address);
    connect(socket_pointer, casted_socket_address, socket_address_size);
}
