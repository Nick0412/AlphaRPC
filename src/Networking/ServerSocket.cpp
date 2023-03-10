#include "Networking/ServerSocket.h"
#include <errno.h>
#include <cstring>
#include <iostream>
#include <stdexcept>

ServerSocket::ServerSocket(const Endpoint& endpoint)
{
    socket_pointer = socket(AF_INET, SOCK_STREAM, 0);

    int option = 1;
    setsockopt(socket_pointer, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    if (socket_pointer == -1)
    {
        std::cout << "Failed to create server socket " << strerror(errno) << "\n";
        throw std::runtime_error("fail");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(endpoint.getPort());
    server_address.sin_addr.s_addr = inet_addr(endpoint.getIpAddress().c_str());

    auto casted_socket_address = reinterpret_cast<const sockaddr*>(&server_address);
    auto socket_address_size = sizeof(server_address);
    auto result_bind = bind(socket_pointer, casted_socket_address, socket_address_size); 

    if (result_bind == -1)
    {
        std::cout << "Failed to bind server socket " << strerror(errno) << "\n";
        throw std::runtime_error("fail");
    }
}

ServerSocket::~ServerSocket()
{
    auto result_close = close(socket_pointer);
    if (result_close == -1)
    {
        std::cout << "Failed to close socket " << strerror(errno) << "\n";
    }
}

void ServerSocket::listenForConnections()
{
    auto result_listen = listen(socket_pointer, 1);
    if (result_listen == -1)
    {
        std::cout << "Failed to listen socket " << strerror(errno) << "\n";
        throw std::runtime_error("fail");
    }
}

DataSocket ServerSocket::acceptConnections()
{
    struct sockaddr_in client_address;
    auto recasted_client_address = reinterpret_cast<sockaddr*>(&client_address);
    socklen_t address_size;

    int connected_socket = accept(socket_pointer, recasted_client_address, &address_size);

    if (connected_socket == -1)
    {
        std::cout << "Failed to accept socket " << strerror(errno) << "\n";
        throw std::runtime_error("fail");
    }

    return DataSocket(connected_socket);
}

