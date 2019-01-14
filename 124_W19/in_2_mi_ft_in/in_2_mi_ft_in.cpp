// in_2_mi_ft_in.cpp
// Created 1/14/2019 3:06:30 PM

#include <iostream>

int main() {
	int miles, feet, inches, input_inches;
	std::cout << "Please enter inches: ";
	std::cin >> input_inches;
	// Determine the whole number of miles 
	// (divide by the number of inches in a mile)
	miles = input_inches / (5280 * 12);
	input_inches = input_inches % (5280 * 12);

	feet = input_inches / 12;
	inches = input_inches % 12;

	std::cout << miles << " mi, " << feet << " ft, " << inches << "in\n";

    
}
