#include "Server.h"

#include "PosixWrapper.h"

Server::Server(const std::string& ip_address, uint16_t port, Types::SocketDomain ip_type, Types::SocketCommunication socket_communication, size_t initial_connection_count)
: ip_address{ip_address}, 
  port{port},
  ip_type{ip_type},
  socket_communication{socket_communication},
  initial_connection_count{initial_connection_count}
{
    server_socket = PosixWrapper::CreateSocketWithExceptionWrapper(ip_type, socket_communication, 0);
}