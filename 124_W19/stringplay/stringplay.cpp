// stringplay.cpp
// Created 4/10/2019 2:15:31 PM

#include <iostream>
#include <string>

int main() {
	std::string text;
	//std::cout << "Please enter some text: ";
	//std::cin >> text;
	//std::cout << "You entered \"" << text << "\"";
	//std::cout << "-----------------------------\n";
	std::cout << "Please enter some text: ";
	std::getline(std::cin, text);
	std::cout << "You entered \"" << text << "\"\n";
	std::cout << text.length() << " characters\n";

	for (unsigned i = 0; i < text.length(); i++) {
		std::cout << '[' << text[i] << ']';
	}
	std::cout << '\n';

	for (char ch : text) {
		std::cout << '<' << ch << '>';
	}
	std::cout << '\n';

	std::cout << text.substr(2, 5) << '\n';

	std::string alphabet;
	//for (int i = 0; i < 26; i++) {
	//	alphabet += static_cast<char>('A' + i);
	//}
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		alphabet += static_cast<char>(ch);
	}
	std::cout << alphabet << '\n';
}
