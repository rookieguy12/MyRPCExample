#ifndef _PROJECT_TYPE_TRAITS
#define _PROJECT_TYPE_TRAITS
#include <type_traits>

template<typename Arg, typename ...Others>
struct is_one_of;

template<typename Arg>
struct is_one_of<Arg> : std::false_type {};

template<typename Arg, typename FirstArg, typename ...Others>
struct is_one_of<Arg, FirstArg, Others...> : std::bool_constant<std::is_same<Arg, FirstArg>::value || is_one_of<Arg, Others...>::value> {};

template<typename Arg, typename ...Others>
constexpr bool is_one_of_v = is_one_of<Arg, Others...>::value;

#endif