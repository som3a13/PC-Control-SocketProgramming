#include "Server.hpp"
#include <iostream>

int main(){

    Server server(8080);
    server.Bind();
    server.Listen();

    while (true) {
        
    server.AcceptClient();
    server.ExecuteClientRequest();

    }

    return 0;
}