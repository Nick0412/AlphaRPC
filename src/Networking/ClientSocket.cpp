#include "Networking/ClientSocket.h"

#include "Networking/Common.h"

#include <iostream>

ClientSocket::ClientSocket(const Endpoint& endpoint)
{
    socket_pointer = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_pointer == -1)
    {
        std::cout << "Failed to create server socket\n";
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(endpoint.getPort());
    server_address.sin_addr.s_addr = inet_addr(endpoint.getIpAddress().c_str());

    if (server_address.sin_addr.s_addr == INADDR_NONE)
    {
        std::cout << "Failed to convert ip address in client\n";
    }
}

ClientSocket::ClientSocket(ClientSocket&& other)
: socket_pointer(other.socket_pointer),
  server_address(other.server_address),
  is_connected(other.is_connected)
{
    other.socket_pointer = 0;
    other.is_connected = false;
}

ClientSocket::~ClientSocket()
{
    if (is_connected)
    {
        close(socket_pointer);
    }
}

void ClientSocket::connectToServer()
{
    auto casted_socket_address = reinterpret_cast<const sockaddr*>(&server_address);
    auto socket_address_size = sizeof(server_address);
    auto result = connect(socket_pointer, casted_socket_address, socket_address_size);

    if (result == -1)
    {
        std::cout << "Failed to connect to server\n";
    }
}

void ClientSocket::sendData(const Types::ByteArray& data_bytes)
{
    NetworkingCommon::sendData(socket_pointer, data_bytes);
}

Types::ByteArray ClientSocket::receiveData(size_t number_of_bytes_to_receive)
{
    return NetworkingCommon::receiveData(socket_pointer, number_of_bytes_to_receive);
}