#include "Server.h"

Server::Server(const std::string& ip_address, uint16_t port, Types::SocketDomain ip_type, Types::SocketCommunication socket_communication, size_t initial_connection_count)
: ip_address(ip_address), 
  port(port),
  ip_type(ip_type),
  socket_communication(socket_communication),
  connected_sockets(initial_connection_count)
{

}