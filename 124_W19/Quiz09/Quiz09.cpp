// Quiz09.cpp
// Created 4/17/2019 2:24:18 PM

#include <iostream>


// Widget class 
// declaration
class Widget {
	int value;
public:
	Widget(int v);
	int get() const;
	void up();
	void down();
};

// Widget method 
// implementations
Widget::Widget(int v) :
	value(v) {}
int Widget::get() const {
	return value;
}
void Widget::up() {
	value++;
}
void Widget::down() {
	value--;
}

void do_it() {
	Widget w1(0), w2(5);
	std::cout << w1.get() << '\n'; // 1.
	std::cout << w2.get() << '\n'; // 2.
	for (int i = 0; i < 3; i++)
		w1.up();
	w2.down();
	w2.down();
	std::cout << w1.get() << '\n'; // 3.
	std::cout << w2.get() << '\n'; // 4. 
}

void print_it() {
	Widget wid1(5);
	Widget wid2(102);

	//for (int i = 0; i < 95; i++)
	//	wid1.up();

	while (wid1.get() != 100)
		wid1.up();

	for (int i = 0; i < 2; i++)
		wid2.down();

	std::cout << wid1.get() << " " << wid2.get() << '\n';
}

int main() {
	do_it();
	std::cout << "-------------------------\n";
	print_it();
}
