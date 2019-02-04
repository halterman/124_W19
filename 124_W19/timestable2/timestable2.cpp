// timestable2.cpp
// Created 2/4/2019 3:03:38 PM

#include <iostream>

int main() {
	std::cout << "Please enter the size of the table: ";
	int size;
	std::cin >> size;

	for (int row = 1; row <= size; row++) {
		for (int column = 1; column <= size; column++) 
			std::cout << row*column << ' ';
		std::cout << '\n';
	}

}

