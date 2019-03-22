// simplevectorexample.cpp
// Created 3/20/2019 3:08:03 PM

#include <iostream>
#include <vector>

void print_vector(std::vector<int> v) {
	int n = v.size();
	for (int i = 0; i < n; i++) 
		std::cout << v[i] << ' ';
	std::cout << '\n';
}

int main() {
	std::vector<int> list;
	list.push_back(10);
	list.push_back(25);
	list.push_back(3);
	list.push_back(7);
	print_vector(list);
}
