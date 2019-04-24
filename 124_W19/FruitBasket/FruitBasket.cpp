// FruitBasket.cpp
// Created 4/22/2019 2:56:17 PM

#include <iostream>
#include <vector>
#include <string>

class Fruit {
public:
	virtual std::string id() const {
		return "fruit";
	}
};


//  "is-a" relationship

class Apple : public Fruit {
public:
	std::string id() const override {
		return "apple";
	}
};

class GoldenDelicious : public Apple {
public:
	std::string id() const override {
		return "golden delicious " + Apple::id();
	}
};

class Orange : public Fruit {
public:
	std::string id() const override {
		return "orange";
	}
};

void print(const std::vector<Fruit *>& a_vec) {
	for (Fruit *a : a_vec) 
		std::cout << a->id() << ' ';
	std::cout << '\n';
}

int main() {
	Apple ap1, ap2, ap3, ap4;
	std::cout << ap1.id() << '\n';
	Orange or1;
	std::cout << or1.id() << '\n';
	std::vector<Fruit *> fruit_basket{ &ap1, &or1, new GoldenDelicious(), 
		                               &ap2, &ap3, &ap4 };
	print(fruit_basket);

	Fruit *f;

	switch (rand() % 3) {
		case 0: f = new Orange;  break;
		case 1: f = new Apple;  break;
		default: f = new GoldenDelicious;  break;
	}

	std::cout << f->id() << '\n';

}
