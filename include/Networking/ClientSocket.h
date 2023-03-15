#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include "Endpoint.h"
#include "Types.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

class ClientSocket
{
private:
    int socket_pointer;
    struct sockaddr_in server_address;
    bool is_connected;

public:
    ClientSocket() = delete;
    ClientSocket(const Endpoint& endpoint);
    ClientSocket(ClientSocket&& other);
    ~ClientSocket();

    void connectToServer();
    void sendData(const Types::ByteArray& data_bytes);
    Types::ByteArray receiveData(size_t number_of_bytes_to_receive);
};

#endif