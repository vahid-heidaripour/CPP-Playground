#include <iostream>
#include <cstddef>

int main() {
	std::byte b{ 35 };
	std::cout << std::to_integer<char>(b) << std::endl;

	b <<= 1;
	std::cout << std::to_integer<char>(b) << std::endl;
	return 0;
}