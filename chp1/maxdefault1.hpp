#include <type_traits>

template<typename T1, typename T2,
	typename RT = typename std::decay<decltype(true ? T1() : T2())>::type >
RT max (T1 a, T2 b)
{
	return b < a ? a : b;
}

