// interactive_vector.cpp
// Created 3/27/2019 2:10:53 PM

#include <iostream>
#include <fstream>
#include <vector>


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

bool contains(const std::vector<int>& v, int seek) {
	for (unsigned i = 0; i < v.size(); i++)
		if (v[i] == seek)
			return true;
	return false;
}

// Removes the first occurrence of del within the vector v.
// (The first occurrence is the one with the lowest index.)
// Does not disturb the relative order of the remaining elements
// in the vector.
// The function returns true if it removes del; otherwise, the
// function returns false.
bool remove(std::vector<int>& v, int del) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (v[i] == del) {
			// Found the element to remove
			while (i < n - 1) {  // Shift the remaining elements forward
				v[i] = v[i + 1];
				i++;
			}
			v.pop_back();
			return true;
		}
	}
	return false;
}

void sort(std::vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[smallest]) {
				smallest = j;
			}
		}
		// Swap smallest and i, if necessary
		if (i != smallest) {
			int temp = v[i];
			v[i] = v[smallest];
			v[smallest] = temp;
		}
	}
}


int main() {
	std::vector<int> vec;
	bool done = false;
	while (!done) {
		char command;
		int value;
		std::cout << "I)nsert D)elete P)rint S)ort Q)uit ";
		std::cin >> command;
		switch (command) {
			case 'i':
			case 'I':
				//std::cout << "You chose to insert\n";
				std::cin >> value;
				vec.push_back(value);
				break;
			case 'd':
			case 'D':
				//std::cout << "You chose to delete\n";
				std::cin >> value;
				if (!remove(vec, value))
					std::cout << "Cannot remove " << value << '\n';
				break;
			case 'p':
			case 'P':
				//std::cout << "You chose to print\n";
				std::cout << vec << '\n';
				break;
			case 's':
			case 'S':
				//std::cout << "You chose to sort\n";
				sort(vec);
				break;
			case 'q':
			case 'Q':
				done = true;
				break;
		}
	}

}
