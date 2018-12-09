#include <iostream>


template<typename T1, typename T2>
constexpr auto max (T1 a, T2 b)
{
	std::cout << a << " " << b << std::endl;
	return b < a ? a : b;
}


