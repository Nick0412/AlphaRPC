#include "Networking/ClientSocket.h"

ClientSocket::ClientSocket(const Endpoint& endpoint)
{
    socket_pointer = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(endpoint.getPort());
    server_address.sin_addr.s_addr = inet_addr(endpoint.getIpAddress().c_str());
}

ClientSocket::~ClientSocket()
{
    close(socket_pointer);
}

void ClientSocket::connectToServer()
{
    auto casted_socket_address = reinterpret_cast<const sockaddr*>(&server_address);
    auto socket_address_size = sizeof(server_address);
    connect(socket_pointer, casted_socket_address, socket_address_size);
}

void ClientSocket::sendData(const Types::ByteArray& data_bytes)
{
    size_t number_of_bytes_sent = 0;
    size_t remaining_number_of_bytes = data_bytes.size();

    while(number_of_bytes_sent < data_bytes.size())
    {
        remaining_number_of_bytes = data_bytes.size() - number_of_bytes_sent;
        // The data function gives us a pointer to the beginning of the vector so we can perform some pointer math here.
        auto offset_pointer_to_data = data_bytes.data() + number_of_bytes_sent;

        number_of_bytes_sent += send(socket_pointer, offset_pointer_to_data, remaining_number_of_bytes, 0);
    }
}

Types::ByteArray ClientSocket::receiveData(size_t number_of_bytes_to_receive)
{
    size_t number_bytes_received = 0;
    size_t remaining_number_of_bytes = number_of_bytes_to_receive;

    Types::ByteArray data_vector(number_of_bytes_to_receive);
    
    while(number_bytes_received < number_of_bytes_to_receive)
    {
        remaining_number_of_bytes = number_of_bytes_to_receive - number_bytes_received;
        auto offset_pointer_to_buffer = data_vector.data() + number_bytes_received;

        number_bytes_received += recv(socket_pointer, offset_pointer_to_buffer, remaining_number_of_bytes, 0);
    }
}