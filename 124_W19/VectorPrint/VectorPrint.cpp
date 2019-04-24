// VectorPrint.cpp
// Created 4/22/2019 2:50:14 PM

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
	int n = v.size();
	os << '{';
	if (n > 0) {
		os << v[0];
		for (int i = 1; i < n; i++)
			os << ", " << v[i];
	}
	os << '}';
	return os;
}

//std::ostream& operator<<(std::ostream& os, std::vector<int> v) {
//	int n = v.size();
//	os << '{';
//	if (n > 0) {
//		os << v[0];
//		for (int i = 1; i < n; i++)
//			os << ", " << v[i];
//	}
//	os << '}';
//	return os;
//}
//
//std::ostream& operator<<(std::ostream& os, std::vector<double> v) {
//	int n = v.size();
//	os << '{';
//	if (n > 0) {
//		os << v[0];
//		for (int i = 1; i < n; i++)
//			os << ", " << v[i];
//	}
//	os << '}';
//	return os;
//}


void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ':';
	}
	std::cout << '\n';
}

void print_array2(int *a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << '$';
	}
	std::cout << '\n';
}

void print_array3(int *a, int n) {
	while (n > 0) {
		std::cout << *a << '=';
		a++;
		n--;
	}
	std::cout << '\n';
}


int main() {
	std::vector<int> vec{ 120, 40, 360, 280 };
	std::cout << vec << '\n';

	std::vector<double> vec2{ 20.5, 40.8, 60.0, 80.1 };
	std::cout << vec2 << '\n';

	int arr[] = { 10, 20, 30, 40, 50 };
	print_array(arr, 5);
	print_array2(arr, 5);
	print_array3(arr, 5);

	std::cout << "---------------------\n";
	std::cout << "Before: " << vec << '\n';
	std::sort(vec.begin(), vec.end());
	std::cout << "After: " << vec << '\n';


    
}
