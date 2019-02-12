// my_square_root_2.cpp
// Created 2/11/2019 2:56:37 PM

#include <iostream>
#include "square_root.h"

int main() {
	for (int i = 1; i <= 16; i++) {
		std::cout << i << "    " << square_root(i)  << '\n';
	}
}
