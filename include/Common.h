#ifndef COMMON_H
#define COMMON_H

#include "Types.h"

/**
 * @namespace Common
 * 
 * @brief A namespace holding commonly used utility function.
 * 
 * TODO: Consider splitting this namespace up by domain.
 */
namespace Common
{
    void SendDataOverSocket(Types::SocketType socket, const Types::ByteBuffer& data);

    Types::ByteBuffer ReceiveDataOverSocket(Types::SocketType socket, std::size_t number_of_bytes);

    Types::ByteBuffer BuildComputeSumMessage(int32_t operand_one, int32_t operand_two);

    Types::ByteBuffer ConvertInt32ToByteArray(uint32_t data);

    Types::ByteBuffer ConvertMessageTypeToByteArray(Types::MessageType message_type);
};

#endif