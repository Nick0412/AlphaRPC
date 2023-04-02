#include "Client.h"

#include "Common.h"
#include "PosixWrapper.h"

Client::Client(const std::string& ip_address, uint16_t port, Types::SocketDomain ip_format, Types::SocketCommunication network_protocol)
: ip_address{ip_address},
  port{port},
  ip_format{ip_format},
  network_protocol{network_protocol}
{
    socket_channel = PosixWrapper::CreateSocketWithExceptionWrapper(ip_format, network_protocol, 0);
}

std::future<int32_t> Client::ComputeSum(int32_t operand_one, int32_t operand_two)
{
    auto message_request = Common::BuildComputeSumMessage(operand_one, operand_two);
    Common::SendDataOverSocket
    // receive(data) = byte_array_res
    // 
}