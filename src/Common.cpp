#include "Common.h"

#include "PosixWrapper.h"

namespace Common
{
    void SendDataOverSocket(Types::SocketType socket, const Types::ByteBuffer& data)
    {
        std::size_t total_bytes_to_send = data.size();
        std::size_t number_of_bytes_sent = 0;

        while (number_of_bytes_sent < total_bytes_to_send)
        {
            std::size_t bytes_remaining = total_bytes_to_send - number_of_bytes_sent;

            number_of_bytes_sent += PosixWrapper::SendDataWithExceptionWrapper(
                socket, data, number_of_bytes_sent, bytes_remaining);
        }
    }

    Types::ByteBuffer ReceiveDataOverSocket(Types::SocketType socket, std::size_t number_of_bytes)
    {
        Types::ByteBuffer data_buffer(number_of_bytes);
        std::size_t number_of_bytes_received = 0;
        
        while (number_of_bytes_received < number_of_bytes)
        {
            std::size_t bytes_remaining = number_of_bytes - number_of_bytes_received;

            number_of_bytes_received += PosixWrapper::ReceiveDataWithExceptionWrapper(
                socket, data_buffer, number_of_bytes_received, bytes_remaining);
        }

        return data_buffer;
    }
};