#include "Networking/ClientSocket.h"

#include <iostream>

int main()
{
    Endpoint e("127.0.0.1", 20001);
    ClientSocket client(e);

    client.connectToServer();

    auto data = client.receiveData(4);

    for(auto c : data)
    {
        std::cout << c;
    }
    
    std::cout << "\n";
    return 0;
}