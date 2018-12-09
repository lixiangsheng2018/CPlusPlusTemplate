#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <array>

void print(){}


template<typename T, typename... Types>
void print (T firstArg, Types... args)
{
	std::cout << firstArg << "\n";
	if (sizeof...(args) > 0) {
		print(args...); // and no print() for no arguments declared
	}
}

template<typename... T>
void printDoubled (T const&... args)
{
	print (args + args...);
}

template<typename C, typename... Idx>
void printElems (C const& coll, Idx... idx)
{
	print (coll[idx]...);
}

template<std::size_t... Idx, typename C>
void printIdx (C const& coll)
{
	print(coll[Idx]...);
}

// type for arbitrary number of indices:
template<std::size_t...>
struct Indices {
};

template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>)
{
	print(std::get<Idx>(t)...);
}


int main()
{
	std::string s("world");
	print(7.5, "hello", s);
	
	printDoubled(7.5, s, std::complex<float>(4,2));

	std::vector<std::string> coll = {"good", "times", "say", "bye"};
	printElems(coll,2,0,3);

	printIdx<2,0,3>(coll);

	std::array<std::string, 5> arr = {"Hello", "my", "new", "!","World"};
	printByIdx(arr, Indices<0, 4, 3>());
}

