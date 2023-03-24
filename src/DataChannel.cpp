#include "DataChannel.h"

#include "Common.h"
#include "Constants.h"

DataChannel::DataChannel(Types::SocketType&& socket)
: data_socket(socket)
{
    socket = Constants::INVALID_SOCKET;
}

DataChannel::~DataChannel()
{
    
}

void DataChannel::Send(const Types::ByteBuffer& data)
{
    Common::SendDataOverSocket(data_socket, data);
}

Types::ByteBuffer DataChannel::Receive(std::size_t number_of_bytes)
{
    return Common::ReceiveDataOverSocket(data_socket, number_of_bytes);
}