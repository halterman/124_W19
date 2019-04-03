// timed_input.cpp
// Created 2/18/2019 2:51:30 PM

#include <iostream>
#include <ctime>

int main() {
	clock_t start_time, end_time;
	int input;
	std::cout << "Please enter an integer: ";
	std::cin >> input;
	std::cout << "Please enter an integer: ";
	start_time = clock();
	std::cin >> input;
	end_time = clock();
	std::cout << static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC << '\n';
}
