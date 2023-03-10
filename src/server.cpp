#include "Networking/ServerSocket.h"

#include <iostream>

int main()
{
    Endpoint e("127.0.0.1", 20001);
    ServerSocket server(e);

    server.listenForConnections();
    auto conn = server.acceptConnections();

    Types::ByteArray data = {'t', 'e', 's', 't'};
    conn.sendData(data);

}