#include <iostream>
#include <string>
#include <sstream>
#include "ServerAPI.h"
#include "UniqueIDConstructor.h"
class ReturnMessageListener {
public:
    virtual void OnMessageReturn(std::string returnMessage)=0;
};

template<typename ReturnType>
class RequestWrapper : public ReturnMessageListener {
public:
    template<typename ...Args>
    RequestWrapper(const std::string funcName, Args&& ...args) {
        // Todo: Send Request and Subscribe itself as an observer of target call;
        std::string remotePorceduleRequest = CreateRequest(uniqueID, funcName, args...);
        unsigned int requestID = UniqueIDConstructor::GetInstance().CreateUniqueID();
        ServerAPI::SendMessage(requestID, remotePorceduleRequest);
        SubscribeObserver(requestID);
    }
    ReturnType Wait() {
        // Todo: WaitAnswer;
        // If Sync: the method itself uses return value as RequestWrapper<ReturnType>::Wait()
        // If Async: the method itself uses return value as RequestWrapper<ReturnType>. which would get blocked until it's notified by the ReturnMessageListener

    }

    virtual void OnMessageReturn(std::string returnMessage) {
        // store the result and use some async method to notify the Wait() function;
    }
private:
    template<typename ...Args>
    static std::string CreateRequest(const std::string& funcName, Args&& ...args) {
        std::stringstream request;
        request << "{" << '\"' << funcName << '\"' << ":";
        DumpArguments(request, args...);
        request << "}";
        return request.str();
    }

    void SubscribeObserver(unsigned int requestID) {
        
    }

};

class RPCModuleAPI {
public:
    template<typename ReturnType, typename ...Args>
    static RequestWrapper<ReturnType> Call(const std::string& funcName, Args&& ...args) {
        return RequestWrapper<ReturnType>(funcName, args...);
    }
};


// Sync ProceduleCall
std::string SyncFunc(std::string a) {
    return RPCModuleAPI::Call<std::string>("SyncFunc", a).Wait();
}

// Async ProceduleCall
RequestWrapper<std::string> AsyncFunc(std::string a) {
    return RPCModuleAPI::Call<std::string>("AsyncFunc", a);
}


int main() {
    Func("5");
}