#include "Messages/AddMessageRequest.h"
#include "Messages/MessageTypes.h"

#include <arpa/inet.h>

const size_t AddMessageRequest::MESSAGE_SIZE_BYTES = 9;
const MessageType AddMessageRequest::MESSAGE_TYPE = MessageType::ADD_MESSAGE;

AddMessageRequest::AddMessageRequest(uint32_t operand_one, uint32_t operand_two)
: operand_one(operand_one), operand_two(operand_two)
{

}

uint32_t AddMessageRequest::getOperandOne() const
{
    return operand_one;
}

uint32_t AddMessageRequest::getOperandTwo() const
{
    return operand_two;
}

AddMessageRequest AddMessageRequest::Deserialize(const Types::ByteArray& data)
{

}

Types::ByteArray AddMessageRequest::Serialize(const AddMessageRequest& msg)
{
    size_t number_of_bytes = sizeof(MessageTypeUnderlying) + 
                             sizeof(msg.getOperandOne()) +
                             sizeof(msg.getOperandTwo());

    Types::ByteArray byte_data(number_of_bytes);

    Types::ByteArray byte_data(MESSAGE_SIZE_BYTES);
    MessageTypeUnderlying type_data = static_cast<MessageTypeUnderlying>(MESSAGE_TYPE);
    uint16_t message_type_network_bytes = htons(type_data);

    byte_data[0] = message_type_network_bytes & 0xFF;
    byte_data[1] = (message_type_network_bytes >> 8) & 0xFF;

    byte_data[2] = msg.getOperandOne() & 0xFF;
    byte_data[3] = (msg.getOperandOne() >> 8) & 0xFF;
    byte_data[4] = (msg.getOperandOne() >> 16) & 0xFF;
    byte_data[5] = (msg.getOperandOne() >> 24) & 0xFF;

    byte_data[6] = msg.getOperandTwo() & 0xFF;
    byte_data[7] = (msg.getOperandTwo() >> 8) & 0xFF;
    byte_data[8] = (msg.getOperandTwo() >> 16) & 0xFF;
    byte_data[9] = (msg.getOperandTwo() >> 24) & 0xFF;
}