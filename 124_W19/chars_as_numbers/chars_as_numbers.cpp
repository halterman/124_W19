// chars_as_numbers.cpp
// Created 2/6/2019 2:51:43 PM

#include <iostream>

int main() {
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		std::cout << ch << ' ';
	}
	std::cout << '\n';

	char letter = 'e';
	std::cout << letter << "   " << toupper(letter) << '\n';
    
}
