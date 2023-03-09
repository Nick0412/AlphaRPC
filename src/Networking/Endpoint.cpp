#include "Networking/Endpoint.h"

Endpoint::Endpoint(const std::string& ip_address, uint16_t port)
: port(port), ip_address(ip_address)
{

}

uint16_t Endpoint::getPort() const
{
    return port;
}

std::string Endpoint::getIpAddress() const
{
    return ip_address;
}