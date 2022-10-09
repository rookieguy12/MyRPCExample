#ifndef _SINGLETON_
#define _SINGLETON_
template<typename RealType>
class Singleton {
public:
    static RealType& GetInstance() {
        static RealType instance;
        return instance;
    }
};
#endif