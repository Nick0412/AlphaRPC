#ifndef DATA_SOCKET_H
#define DATA_SOCKET_H

#include "Types.h"

#include <sys/socket.h>
#include <unistd.h>

class DataSocket
{
private:
    int socket_pointer;

public:
    DataSocket(int socket_pointer);
    ~DataSocket();
    
    void sendData(const Types::ByteArray& data_bytes);
    Types::ByteArray receiveData(size_t number_of_bytes_to_receive);
};

#endif