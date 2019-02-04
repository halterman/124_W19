// switch_example.cpp
// Created 2/4/2019 2:24:32 PM

#include <iostream>

int main() {
	bool done = false;

	while (!done) {
		std::cout << "O)pen S)ave P)rint Q)uit: ";
		char input;
		std::cin >> input;
		switch (input) {
			case 'O':
			case 'o':
				std::cout << "You chose to open a new document\n";
				break;
			case 'S':
			case 's':
				std::cout << "You chose to save your document\n";
				break;
			case 'P':
			case 'p':
				std::cout << "You chose to print\n";
				break;
			case 'T':
			case 't':
				std::cout << "You chose to make a text box\n";
				break;
			case 'Q':
			case 'q':
				std::cout << "You chose to quit\n";
				done = true;
				break;
			default:
				std::cout << input << " is not an acceptable option\n";
		}

	}
	std::cout << "Program done\n";
}
