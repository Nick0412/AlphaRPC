#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Types.h"

namespace Constants
{
    constexpr Types::SocketType INVALID_SOCKET = -1;
    constexpr int SEND_DATA_ERROR = -1;
    constexpr int RECEIVE_DATA_ERROR = -1;

    constexpr uint32_t UINT_32_NUMBER_OF_BYTES = 4;
    constexpr uint32_t MESSAGE_TYPE_NUMBER_OF_BYTES = 4;
    constexpr uint32_t MESSAGE_SIZE_NUMBER_OF_BYTES = 4;
};

#endif
