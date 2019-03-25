// simplevectorexample.cpp
// Created 3/20/2019 3:08:03 PM

#include <iostream>
#include <vector>

//void print_vector(std::vector<int> v) {
//	int n = v.size();
//	std::cout << "The vector contains ";
//	for (int i = 0; i < n; i++) 
//		std::cout << v[i] << ' ';
//	std::cout << ".\n";
//}
//void print_vector2(std::vector<double> v) {
//	int n = v.size();
//	std::cout << "The vector contains ";
//	for (int i = 0; i < n; i++)
//		std::cout << v[i] << ' ';
//	std::cout << ".\n";
//}

template <typename T>
void print_vector(std::vector<T> v) {
	int n = v.size();
	std::cout << "The vector contains ";
	for (int i = 0; i < n; i++) 
		std::cout << v[i] << ' ';
	std::cout << ".\n";
}


int main() {
	// First make an empty vector, and then add contents
	std::vector<int> list;
	print_vector(list);
	list.push_back(10);
	print_vector(list);
	list.push_back(25);
	print_vector(list);
	list.push_back(3);
	print_vector(list);
	list.push_back(7);
	print_vector(list);

	// Make a vector that contains five elements
	std::vector<int> list2(5);
	for (int i = 0; i < list2.size(); i++) {
		list2[i] = 10 * i;
	}

	print_vector(list2);

	// Make a vector that contains five 7s
	std::vector<int> list3(5, 7);
	print_vector(list3);

	// Make a vector containing 3, 2, -1, 100, 45, 67
	std::vector<int> list4{3, 2, -1, 100, 45, 67};
	print_vector(list4);

	std::vector<int> int_numbers{ 10, 20, 30, 40 };
	print_vector(int_numbers);

	std::vector<double> double_numbers{0.5, 1.0, 1.5, 2.0, 2.5};
	print_vector(double_numbers);
}
