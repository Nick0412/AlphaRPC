#ifndef DATA_CHANNEL_H
#define DATA_CHANNEL_H

#include "Types.h"

class DataChannel
{
private:
    Types::SocketType data_socket;

public:
    /**
     * @brief Disable calling the default constructor.
     * 
     */
    DataChannel() = delete;

    /**
     * @brief Disable copy constructor.
     * 
     */
    DataChannel(const DataChannel& other) = delete;

    /**
     * @brief Construct DataChannel from a r-value reference to a socket.
     * This is to pass the lifetime of the socket to this class so it can be
     * handled internally.
     * 
     */
    DataChannel(Types::SocketType&& socket);

    /**
     * @brief Destruct the data channel and close the socket file descriptor.
     * 
     */
    ~DataChannel();

    /**
     * @brief Send the byte data through the socket.
     * 
     * @param data The list of bytes to send.
     */
    void Send(const Types::ByteBuffer& data);

    /**
     * @brief Receive a number of bytes of the socket and place into a buffer.
     * 
     * @param number_of_bytes The number of bytes to receive from the socket.
     * @return Types::ByteBuffer The actual data bytes read from the socket.
     */
    Types::ByteBuffer Receive(std::size_t number_of_bytes);
};

#endif