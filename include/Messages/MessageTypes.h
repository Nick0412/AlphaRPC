#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H

#include <cstdint>
#include <type_traits>

enum class MessageType : uint16_t
{
    ADD_MESSAGE = 1,
    DELETE_MESSAGE = 2
};

using MessageTypeUnderlying = std::underlying_type<MessageType>::type;

#endif