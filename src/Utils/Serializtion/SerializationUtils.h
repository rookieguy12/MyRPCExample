#ifndef _SERIALIZATIONUTILS_
#define _SERIALIZATIONUTILS_
#include "project_type_traits.h"
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

template<typename FirstArg, typename...Args>
void DumpArguments(std::stringstream& dumpStream, FirstArg&& firstArg, Args&&... args) {
    Dump<FirstArg>(dumpStream, firstArg);
    DumpArguments(dumpStream, args...);
}

void DumpArguments(std::stringstream& dumpStream) {}

template<typename Arg>
std::enable_if_t<is_one_of_v<std::remove_reference_t<Arg>, std::string, char *>, void> Dump(std::stringstream& dumpStream, Arg&& arg) {
    dumpStream << '\"' << arg <<'\"';
}

template<typename Arg>
std::enable_if_t<std::is_arithmetic_v<Arg>, void> Dump(std::stringstream& dumpStream, Arg&& arg) {
    dumpStream << arg;
}

#endif