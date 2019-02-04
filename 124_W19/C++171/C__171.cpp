// C__171.cpp
// Created 1/30/2019 2:09:39 PM

#include <iostream>

//int main() {
//	int input = 0, even_count = 0;
//	std::cout << "Please enter nonnegative integers, a negative number terminates.\n";
//	while (input >= 0) {
//		std::cin >> input;
//		if (input >= 0 && input % 2 == 0) {
//			even_count++;
//		}
//	}
//	std::cout << "You entered " << even_count << " even numbers\n";
//}


int main() {
	int input = 0, even_count = 0;
	std::cout << "Please enter nonnegative integers, a negative number terminates.\n";
	std::cin >> input;
	while (input >= 0) {
		if (input % 2 == 0) {
			even_count++;
		}
		std::cin >> input;
	}
	std::cout << "You entered " << even_count << " even numbers\n";
}
