#include "Networking/Common.h"

#include <cstdint>
#include <sys/socket.h>

namespace NetworkingCommon
{
    void sendData(int socket_pointer, const Types::ByteArray& data_bytes)
    {
        std::size_t number_of_bytes_sent = 0;
        std::size_t remaining_number_of_bytes = data_bytes.size();

        while(number_of_bytes_sent < data_bytes.size())
        {
            remaining_number_of_bytes = data_bytes.size() - number_of_bytes_sent;
            // The data function gives us a pointer to the beginning of the vector so we can perform some pointer math here.
            auto offset_pointer_to_data = data_bytes.data() + number_of_bytes_sent;

            number_of_bytes_sent += send(socket_pointer, offset_pointer_to_data, remaining_number_of_bytes, 0);
        }
    }

    Types::ByteArray receiveData(int socket_pointer, std::size_t number_of_bytes_to_receive)
    {
        std::size_t number_bytes_received = 0;
        std::size_t remaining_number_of_bytes = number_of_bytes_to_receive;

        Types::ByteArray data_vector(number_of_bytes_to_receive);
        
        while(number_bytes_received < number_of_bytes_to_receive)
        {
            remaining_number_of_bytes = number_of_bytes_to_receive - number_bytes_received;
            auto offset_pointer_to_buffer = data_vector.data() + number_bytes_received;

            number_bytes_received += recv(socket_pointer, offset_pointer_to_buffer, remaining_number_of_bytes, 0);
        }

        return data_vector;
    }
}