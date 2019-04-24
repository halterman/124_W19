// ObjectPointer.cpp
// Created 4/22/2019 2:42:37 PM

#include <iostream>

class Widget {
public:
	int data;
	Widget(int data) : data(data) {}
};

int main() {
	Widget w1(5);
	std::cout << w1.data << '\n';
	Widget* wp = new Widget(10);
	std::cout << (*wp).data << '\n';
	std::cout << wp->data << '\n';

	delete wp;
}
