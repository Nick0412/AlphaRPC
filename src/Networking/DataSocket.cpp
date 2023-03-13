#include "Networking/DataSocket.h"

#include "Networking/Common.h"

DataSocket::DataSocket(int socket_pointer)
: socket_pointer(socket_pointer)
{

}

DataSocket::~DataSocket()
{
    close(socket_pointer);
}

void DataSocket::sendData(const Types::ByteArray& data_bytes)
{
    NetworkingCommon::sendData(socket_pointer, data_bytes);
}

Types::ByteArray DataSocket::receiveData(size_t number_of_bytes_to_receive)
{
    return NetworkingCommon::receiveData(socket_pointer, number_of_bytes_to_receive);
}