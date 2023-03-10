#include "Delegator/Delegate.h"
#include "Messages/AddMessageRequest.h"
#include "Messages/AddMessageResponse.h"

namespace Delegator
{
    void delegateFunction(
        DataSocket& data_socket,
        const MessageType& message_type,
        const Types::ByteArray& data)
    {
        switch(message_type)
        {
            case MessageType::ADD_MESSAGE:
                handleAddMessage(data_socket, data);
                break;
            case MessageType::DELETE_MESSAGE:
                handleDeleteMessage(data_socket, data);
                break;
            default:
                break;
        }
    }

    /**
     * 1. Decipher message
     * 2. Enact message logic
     * 3. Build response and encode
     * 4. Send response
    */
    void handleAddMessage(DataSocket& data_socket, const Types::ByteArray& data)
    {
        // 1.
        AddMessageRequest message_request = AddMessageRequest::Deserialize(data);

        // 2.
        uint32_t result = message_request.getOperandOne() + message_request.getOperandTwo();

        // 3.
        AddMessageResponse message_response(result);
        Types::ByteArray return_data = AddMessageResponse::Serialize(message_response);
        // TODO: Need to pad with message size.
        Types::ByteArray full_return_data;

        // 4.
        data_socket.sendData(full_return_data);
    }

    void handleDeleteMessage(DataSocket& data_socket, const Types::ByteArray& data)
    {
        // do nothing
    }
};