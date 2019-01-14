// mi_ft_in_2_in.cpp
// Created 1/14/2019 2:47:43 PM

#include <iostream>

int main() {
	int miles, feet, inches;
	std::cout << "Please enter the miles, feet, and inches: ";
	std::cin >> miles >> feet >> inches;

//	int total_inches = miles * 5280 * 12;
//	total_inches = total_inches + (feet * 12);
//	total_inches = total_inches + inches;

	int total_inches = (miles * 5280 * 12) + (feet * 12) + inches;

	std::cout << "Total inches: " << total_inches << '\n';

}
