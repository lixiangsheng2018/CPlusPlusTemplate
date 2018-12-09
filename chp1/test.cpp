#include <iostream>
#include <string>
#include "maxconstexpr.hpp"

int main()
{

	int a[::max(sizeof(char),1000u)];
	std::cout << sizeof(a) << std::endl;
}

