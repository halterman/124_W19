// mathfunc.cpp
// Created 2/25/2019 2:45:58 PM

#include <iostream>
#include <functional>

int add(int m, int n) {
	return m + n;
}

int multiply(int m, int n) {
	return m * n;
}

//int evaluate(int (*f)(int, int), int n1, int n2) {
int evaluate(std::function<int(int, int)> f, int n1, int n2) {
	return f(n1, n2);
}

int main() {
	std::cout << add(3, 5) << '\n';
	std::cout << multiply(4, 5) << '\n';
	std::cout << evaluate(add, 10, 87) << '\n';
	std::cout << evaluate(multiply, 10, 87) << '\n';
    
}
