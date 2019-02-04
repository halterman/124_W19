// timestable1.cpp
// Created 2/4/2019 2:59:26 PM

#include <iostream>

int main() {
	std::cout << "Please enter the size of the table: ";
	int size;
	std::cin >> size;

	for (int row = 1; row <= size; row++) {
		std::cout << "Row #" << row << '\n';
	}
    
}
