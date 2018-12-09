#include "tackpartspec.hpp"
#include <iostream>
#include <string>

int main()
{
	Stack< int*> ptrStack; // stack of pointers (specialimplementation)
	ptrStack.push(new int{42});
	std::cout << *(ptrStack.top()) << "\n";
	delete ptrStack.pop();
}

