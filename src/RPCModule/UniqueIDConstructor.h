#ifndef _UNIQUE_ID_CONSTRUCTOR_
#define _UNIQUE_ID_CONSTRUCTOR_
#include "Singleton.h"
class UniqueIDConstructor : public Singleton<UniqueIDConstructor> {
    unsigned int CreateUniqueID();
};

#endif