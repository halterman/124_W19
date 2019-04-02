// TwoDimensionalVector.cpp
// Created 4/1/2019 2:53:30 PM

#include <iostream>
#include <vector>

void print_matrix(const std::vector<std::vector<double>>& array) {
	for (auto row : array) {
		for (auto elem : row) {
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	std::vector<std::vector<double>> m{ {1, 2, 3},
									    {2, 4},
										{0, 4, 1, 10, -3, 8},
									    {0, 4, 1} };
	print_matrix(m);
}
