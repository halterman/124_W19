// _1_16_addfifths.cpp
// Created 1/16/2019 1:57:14 PM

#include <iostream>
int main() {
	double one = 1.0,
		   one_fifth = 1.0 / 5.0,
		   zero = one - one_fifth - one_fifth - one_fifth
		          - one_fifth - one_fifth;
	std::cout << "one = " << one << ", one_fifth = " << one_fifth
		      << ", zero = " << zero << '\n';
}
