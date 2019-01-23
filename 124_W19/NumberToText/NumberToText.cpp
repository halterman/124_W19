// NumberToText.cpp
// Created 1/23/2019 2:31:33 PM

#include <iostream>

int main() {
	std::cout << "Please enter an integer: ";
	int number;
	std::cin >> number;
	if (number == 1) 
		std::cout << "one\n";
	else if (number == 2) 
		std::cout << "two\n";
	else if (number == 3) 
		std::cout << "three\n";
	else if (number == 4) 
		std::cout << "four\n";
	else if (number == 5) 
		std::cout << "five\n";
	else if (number < 1) 
		std::cout << "Too small\n";
	else
		std::cout << "Too big\n";
    
}
