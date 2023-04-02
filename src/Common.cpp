#include "Common.h"

#include "PosixWrapper.h"
#include "Constants.h"

#include <algorithm>
#include <iterator>
#include <type_traits>

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

    Types::ByteBuffer BuildComputeSumMessage(int32_t operand_one, int32_t operand_two)
    {
        uint32_t message_size = Constants::MESSAGE_SIZE_NUMBER_OF_BYTES +
                                Constants::MESSAGE_TYPE_NUMBER_OF_BYTES +
                                Constants::UINT_32_NUMBER_OF_BYTES +
                                Constants::UINT_32_NUMBER_OF_BYTES;

        Types::ByteBuffer request_byte_array(message_size);

        auto size_bytes = ConvertInt32ToByteArray(message_size);
        auto type_bytes = ConvertMessageTypeToByteArray(Types::MessageType::COMPUTE_SUM_MESSAGE);
        auto operand_one_bytes = ConvertInt32ToByteArray(operand_one);
        auto operand_two_bytes = ConvertInt32ToByteArray(operand_two);

        auto iter = request_byte_array.begin();
        std::copy(size_bytes.begin(), size_bytes.end(), iter);
        std::advance(iter, Constants::MESSAGE_SIZE_NUMBER_OF_BYTES);

        std::copy(type_bytes.begin(), type_bytes.end(), iter);
        std::advance(iter, Constants::MESSAGE_TYPE_NUMBER_OF_BYTES);

        std::copy(operand_one_bytes.begin(), operand_one_bytes.end(), iter);
        std::advance(iter, Constants::UINT_32_NUMBER_OF_BYTES);

        std::copy(operand_two_bytes.begin(), operand_two_bytes.end(), iter);

        return request_byte_array;
    }

    Types::ByteBuffer ConvertInt32ToByteArray(uint32_t data)
    {
        Types::ByteBuffer data_bytes(4);
        data_bytes[0] = data & 0xFF;
        data_bytes[1] = (data >> 8) & 0xFF;
        data_bytes[2] = (data >> 16) & 0xFF;
        data_bytes[3] = (data >> 24) & 0xFF;

        return data_bytes;
    }

    Types::ByteBuffer ConvertMessageTypeToByteArray(Types::MessageType message_type)
    {
        using MessageTypeUnderlying = std::underlying_type_t<Types::MessageType>;
        MessageTypeUnderlying data = static_cast<MessageTypeUnderlying>(message_type);
                
        return ConvertInt32ToByteArray(data);
    }
};