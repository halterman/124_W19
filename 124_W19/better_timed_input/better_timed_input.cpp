// better_timed_input.cpp
// Created 4/3/2019 2:50:49 PM

#include <iostream>
#include "stopwatch.h"

int main() {
	int input;
	std::cout << "Please enter an integer: ";
	std::cin >> input;
	std::cout << "Please enter an integer: ";
	start_clock();
	std::cin >> input;
	stop_clock();
	std::cout << elapsed_clock() << '\n';
}
