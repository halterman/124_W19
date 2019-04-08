// best_timed_input_alt.cpp
// Created 4/8/2019 2:37:58 PM

#include <iostream>
#include <ctime>

class Stopwatch {
	clock_t start_time;
	clock_t end_time;
public:
	void start() {
		start_time = clock();
	}
	void stop() {
		end_time = clock();
	}
	double elapsed() {
		return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	}
};


int main() {
	int input;
	Stopwatch timer;
	std::cout << "(Best alternate version) ";
	std::cout << "Please enter an integer: ";
	std::cin >> input;
	std::cout << "Please enter an integer: ";
	timer.start();
	std::cin >> input;
	timer.stop();
	std::cout << timer.elapsed() << '\n';
}

