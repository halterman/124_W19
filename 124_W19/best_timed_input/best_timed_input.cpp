// best_timed_input.cpp
// Created 4/3/2019 3:05:58 PM

#include <iostream>
#include "stopwatch.h"

int main() {
	int input;
	Stopwatch timer;
	std::cout << "(Best) ";
	std::cout << "Please enter an integer: ";
	std::cin >> input;
	std::cout << "Please enter an integer: ";
	timer.start();
	std::cin >> input;
	timer.stop();
	std::cout << timer.elapsed() << '\n';
}