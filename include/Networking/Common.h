#ifndef NETWORK_COMMON_H
#define NETWORK_COMMON_H

#include "Types.h"

#include <cstdint>

namespace NetworkingCommon
{
    void sendData(int socket_pointer, const Types::ByteArray& data_bytes);

    Types::ByteArray receiveData(int socket_pointer, std::size_t number_of_bytes_to_receive);
};

#endif