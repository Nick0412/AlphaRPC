#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <cstdint>
#include <array>
#include <string>

class Endpoint
{
public:
    using IpType = std::array<uint8_t, 4>;

private:
    uint16_t port;
    std::string ip_address;

public:
    Endpoint(const std::string& ip_address, uint16_t port);
    uint16_t getPort() const;
    std::string getIpAddress() const;
    
};

#endif