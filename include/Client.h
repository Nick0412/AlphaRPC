#ifndef CLIENT_H
#define CLIENT_H

#include "Types.h"

#include <cstdint>
#include <string>
#include <future>

class Client
{
private:
    Types::SocketType socket_channel;
    uint16_t port;
    std::string ip_address;
    Types::SocketDomain ip_format;
    Types::SocketCommunication network_protocol;
    

public:
    Client(const std::string& ip_address, uint16_t port, Types::SocketDomain ip_format, Types::SocketCommunication network_protocol);

    std::future<int32_t> ComputeSum(int32_t operand_one, int32_t operand_two);

public:
    Client() = delete;
    Client(const Client& other) = delete;
    Client(Client&& other) = delete;
    Client& operator=(const Client& other) = delete;
    Client& operator=(Client&& other) = delete;
};

#endif

