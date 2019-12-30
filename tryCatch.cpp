#include <iostream>
#include <stdexcept>

double divideNumbers(double numerator, double denominator) {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be 0!");
	}

	return numerator / denominator;
}

int main() {
	try {
		std::cout << divideNumbers(2.5, .5) << std::endl;
		std::cout << divideNumbers(2.3, 0) << std::endl;
		std::cout << divideNumbers(4.5, 1.5) << std::endl; // the third call is never executed
	}
	catch (const std::invalid_argument& exception) {
		std::cout << "Exception caught: " << exception.what() << std::endl;
	}

	return 0;
}