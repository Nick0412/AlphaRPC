#include "PosixWrapper.h"

#include "Constants.h"

#include <cstring>
#include <stdexcept>
#include <sstream>
#include <sys/socket.h>

namespace PosixWrapper
{
    // TODO: need to check for out of bounds indexing of the array
    std::size_t SendDataWithExceptionWrapper(
        Types::SocketType socket,
        const Types::ByteBuffer& data,
        std::size_t offset_into_data_array,
        std::size_t number_of_bytes_remaining)
    {
        int result = send(socket, data.data() + offset_into_data_array, number_of_bytes_remaining, 0);

        if (result == Constants::SEND_DATA_ERROR)
        {
            std::stringstream msg;
            msg << "Failed to send data on socket. " << std::strerror(errno) << "\n";
            throw std::runtime_error(msg.str());
        }

        return result;
    }

    std::size_t ReceiveDataWithExceptionWrapper(
        Types::SocketType socket,
        Types::ByteBuffer& data,
        std::size_t offset_into_data_array,
        std::size_t number_of_bytes_remaining)
    {
        int result = recv(socket, data.data() + offset_into_data_array, number_of_bytes_remaining, 0);

        if (result == Constants::RECEIVE_DATA_ERROR)
        {
            std::stringstream msg;
            msg << "Failed to receive data on socket. " << std::strerror(errno) << "\n";
            throw std::runtime_error(msg.str());
        }

        return result;
    }

    Types::SocketType CreateSocketWithExceptionWrapper(
        Types::SocketDomain ip_type,
        Types::SocketCommunication socket_communication,
        int protocol)
    {
        int result = socket(
            static_cast<int>(ip_type),
            static_cast<int>(socket_communication),
            protocol);

        if (result == Constants::INVALID_SOCKET)
        {
            std::stringstream msg;
            msg << "Failed to create socket. " << std::strerror(errno) << "\n";
            throw std::runtime_error(msg.str());
        }

        return result;
    }
}