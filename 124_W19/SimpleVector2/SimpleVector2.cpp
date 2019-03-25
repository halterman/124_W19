// SimpleVector2.cpp
// Created 3/25/2019 2:28:39 PM

#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
void print_vector(std::ostream& os, std::vector<T> v) {
	//int n = v.size();
	os << "The vector contains ";
	for (unsigned i = 0; i < v.size(); i++)
		os << v[i] << ' ';
	os << ".\n";
}

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


int main() {
	std::vector<int> int_numbers{ 10, 20, 30, 40 };
	print_vector(std::cout, int_numbers);

	std::vector<double> double_numbers{ 0.5, 1.0, 1.5, 2.0, 2.5 };
	print_vector(std::cout, double_numbers);

	std::ofstream out("temp.txt");
	print_vector(out, double_numbers);

	std::cout << int_numbers << '\n';

	std::cout << "------------------------'\n";
	std::vector<int> other_list;
	std::cout << other_list << '\n';
	other_list.push_back(200);
	std::cout << other_list << '\n';
	other_list.push_back(-7);
	std::cout << other_list << '\n';
	other_list.push_back(87);
	std::cout << other_list << '\n';
	other_list.push_back(44);
	std::cout << other_list << '\n';

	std::cout << "The vector is " << other_list << "---done\n";

	std::ofstream other_out("other-out.txt");
	other_out << other_list << '\n';

	std::cout << "------------------------'\n";
	std::cout << other_list << '\n';
	std::cout << "Contains -6? " << std::boolalpha << contains(other_list, -6) << '\n';
	std::cout << "Contains -7? " << std::boolalpha << contains(other_list, -7) << '\n';
	std::cout << other_list << '\n';

	std::cout << other_list[20] << '\n';

}
