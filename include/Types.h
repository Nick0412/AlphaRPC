#ifndef TYPES_H
#define TYPES_H

#include <sys/socket.h>
#include <cstdint>
#include <utility>
#include <vector>

/**
 * @namespace Types
 * 
 * @brief Namespace to define and alias commonly used types.
 * 
 */
namespace Types
{
    using ByteBuffer = std::vector<uint8_t>;
    using SocketType = int;
    
    enum class SocketDomain : int
    {
        IPv4 = AF_INET,
        IPv6 = AF_INET6,
        LOCAL = AF_UNIX
    };

    enum class SocketCommunication : int
    {
        TCP = SOCK_STREAM,
        UDP = SOCK_DGRAM,
        RAW = SOCK_RAW
    };

    enum class MessageType : uint32_t
    {
        COMPUTE_SUM_MESSAGE = 1
    };
};

#endif