#ifndef CLIENT_SERVICE_H
#define CLIENT_SERVICE_H

#include "Networking/ClientSocket.h"

#include <future>
#include <cstdint>

class ClientService
{
private:
    ClientSocket client_service;

public:
    ClientService(ClientSocket& client_socket);

    std::future<uint32_t> add(uint32_t operand_one, uint32_t operand_two);
};

#endif