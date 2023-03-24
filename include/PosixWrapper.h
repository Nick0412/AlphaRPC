#ifndef POSIX_WRAPPER_H
#define POSIX_WRAPPER_H

#include "Types.h"

/**
 * @namespace PosixWrapper
 * 
 * @brief A namespace to hold POSIX functions and system calls that are wrapped in
 * exceptions for easier error checking.
 */
namespace PosixWrapper
{
    /**
     * @brief Sends the byte data over the socket and watches for errors. These errors
     * are then wrapped in an exception where they will be thrown to the caller.
     * 
     * @param socket The connected network socket.
     * @param data The byte data to send over the socket.
     * @param offset_into_data_array Index into the byte array of where to send from.
     * @param number_of_bytes_remaining Number of bytes in the array that still have to be send.
     * @return std::size_t The number of bytes actually send on this call. 
     */
    std::size_t SendDataWithExceptionWrapper(
        Types::SocketType socket,
        const Types::ByteBuffer& data,
        std::size_t offset_into_data_array,
        std::size_t number_of_bytes_remaining);

    /**
     * @brief 
     * 
     * @param socket The connected network socket.
     * @param[out] data The buffer to read the data into.
     * @param offset_into_data_array Index in the buffer where to place the remaining bytes.
     * @param number_of_bytes_remaining How many bytes to read.
     * @return std::size_t The number of bytes actually received.
     */
    std::size_t ReceiveDataWithExceptionWrapper(
        Types::SocketType socket,
        Types::ByteBuffer& data,
        std::size_t offset_into_data_array,
        std::size_t number_of_bytes_remaining);

    Types::SocketType CreateSocketWithExceptionWrapper(
        Types::SocketDomain ip_type,
        Types::SocketCommunication socket_communication,
        int protocol);
};

#endif