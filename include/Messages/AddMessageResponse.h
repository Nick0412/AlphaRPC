#ifndef ADD_MESSAGE_RESPONSE_H
#define ADD_MESSAGE_RESPONSE_H

#include "Networking/Types.h"

#include <cstdint>
#include <memory>

class AddMessageResponse
{
private:
    uint32_t result_sum;

public:
    AddMessageResponse(uint32_t result_sum);

    static AddMessageResponse Deserialize(const Types::ByteArray& data);
    static Types::ByteArray Serialize(const AddMessageResponse& data);
};

#endif