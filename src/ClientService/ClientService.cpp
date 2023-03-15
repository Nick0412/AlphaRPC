#include "ClientService/ClientService.h"

#include "Messages/AddMessageRequest.h"

#include <utility>

ClientService::ClientService(ClientSocket& client_socket)
: client_service(std::move(client_socket))
{

}

std::future<uint32_t> ClientService::add(uint32_t operand_one, uint32_t operand_two)
{
    AddMessageRequest request(operand_one, operand_two);
    Types::ByteArray data_bytes = AddMessageRequest::Serialize(request);

    client_service.sendData(data_bytes);
}