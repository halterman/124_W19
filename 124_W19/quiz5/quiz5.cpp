#include <iostream>

int process(int n) {
	int result;
	if (n < 10)
		result = n + 5;
	else
		result = n - 10;
	return result;
}

int compute(int n) {
	if (n > 10)
		return n;
	else
		return n + compute(n + 2);
}

int factor = 3;

int calculate(int n) {
	int result = n * factor;
	factor++;
	return result;
}

int main() {
	int value = 200;
	std::cout << process(0) << '\n';  //  1. 
	std::cout << process(value) << '\n';     //  2.
	std::cout << process(10) << '\n';    //  3.
	std::cout << process(process(6)) << '\n';    //  4.
	std::cout << process(3 * value - 2) << '\n';   //  5.
	// - - - - - - - - - - - - - - - - - - - - - - - - - -
	std::cout << compute(25) << '\n';    //  6. 
	std::cout << compute(5) << '\n';       //  7.
	std::cout << compute(0) << '\n';     //  8.
	// - - - - - - - - - - - - - - - - - - - - - - - - - -
	std::cout << calculate(4) << '\n';       //  9. 
	std::cout << calculate(2) << '\n';      // 10.
}