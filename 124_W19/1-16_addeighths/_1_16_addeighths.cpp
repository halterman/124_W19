// _1_16_addeighths.cpp
// Created 1/16/2019 1:59:00 PM

#include <iostream>
int main() {
	double one = 1.0,
		   one_eighth = 1.0 / 8.0,
		   zero = one - one_eighth - one_eighth - one_eighth
		              - one_eighth - one_eighth - one_eighth
		              - one_eighth - one_eighth;
	std::cout << "one = " << one << ", one_eighth = " << one_eighth
		      << ", zero = " << zero << '\n';
}
