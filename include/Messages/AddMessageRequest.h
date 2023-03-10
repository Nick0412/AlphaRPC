#ifndef ADD_MESSAGE_REQUEST_H
#define ADD_MESSAGE_REQUEST_H

#include "Networking/Types.h"

#include <cstdint>
#include <memory>

class AddMessageRequest
{
private:
    uint32_t operand_one;
    uint32_t operand_two;

public:
    AddMessageRequest(uint32_t operand_one, uint32_t operand_two);
    uint32_t getOperandOne() const;
    uint32_t getOperandTwo() const;

    static AddMessageRequest Deserialize(const Types::ByteArray& data);
    static Types::ByteArray Serialize(const AddMessageRequest& data);
};

#endif