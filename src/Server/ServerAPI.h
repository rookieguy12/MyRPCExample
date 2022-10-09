#ifndef _SERVER_API_
#define _SERVER_API_
#include <string>

class ServerAPI {
public:
    static void SendMessage(const std::string& message);
    static void OnMessageReceive(const std::string& message);
};

#endif