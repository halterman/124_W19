// BinaryConvert.cpp
// Created 1/23/2019 2:48:13 PM

#include <iostream>

int main() {
	int count = 0;
	while (count < 5) {
		int input;
		std::cout << "Please enter a value in the range 0...1,023: ";
		std::cin >> input;

		if (0 <= input && input <= 1023) {
			if (input >= 512)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 512;
			if (input >= 256)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 256;
			if (input >= 128)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 128;
			if (input >= 64)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 64;
			if (input >= 32)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 32;
			if (input >= 16)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 16;
			if (input >= 8)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 8;
			if (input >= 4)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 4;
			if (input >= 2)
				std::cout << 1;
			else
				std::cout << 0;
			input %= 2;
			std::cout << input << '\n';
		}
		count++;
	}
}
