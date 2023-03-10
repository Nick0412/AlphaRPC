#ifndef DELEGATE_H
#define DELEGATE_H

#include "Networking/Types.h"
#include "DataSocket.h"
#include "Messages/MessageTypes.h"

namespace Delegator
{
    void delegateFunction(
        DataSocket& data_socket,
        const MessageType& message_type,
        const Types::ByteArray& data);

    void handleAddMessage(DataSocket& data_socket, const Types::ByteArray& data);

    void handleDeleteMessage(DataSocket& data_socket, const Types::ByteArray& data);
};

#endif