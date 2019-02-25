// Bluebox.cpp
// Created 2/25/2019 2:57:48 PM

#include <iostream>
#include <GL/sgl.hpp>

double current_x;
double current_y;

void paint() {
	sgl::set_color(sgl::BLUE);
	sgl::fill_rectangle(current_x, current_y, 30, 30);
}

void mouse_pressed(double x, double y, sgl::MouseButton) {
	std::cout << "(" << x << ", " << y << ")\n";
	current_x = x;
	current_y = y;
	sgl::update_window();
}

int main() {
	sgl::create_window("Blue Box", 0, 300, 0, 300);
	sgl::set_paint_function(paint);
	sgl::set_mouse_pressed_function(mouse_pressed);
	sgl::run_window();
}
