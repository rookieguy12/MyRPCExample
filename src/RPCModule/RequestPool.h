#ifndef _REQUESTPOOL_H_
#define _REQUESTPOOL_H_
#include "Utils/Singleton.h"
#include "RPCExample.h"
#include <map>
class RequestPool : public Singleton<RequestPool> {
public:
    void SubscribeObserver(unsigned int requestID, ReturnMessageListener* listener) {
        requestMap[requestID] = listener;
    }

    bool ContainRequestID(unsigned int requ);

    void OnMessageReceive(unsigned int reqeustID, std::string& receiveMessage) {
        if (requestMap.find(reqeustID)) {
            requestMap[reqeustID]->OnMessageReturn(receiveMessage);
        }
    }
private:
    std::map<unsigned int, ReturnMessageListener *> requestMap;
};
#endif
