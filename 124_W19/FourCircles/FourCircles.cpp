// Simple example showing how to draw lines with the SGL library

#include <GL/sgl.hpp>  // Use #include "sgl.hpp" on macOS
#include <cmath>  

enum class Circle { None, Left, Right, Top, Bottom };

Circle active_circle = Circle::None;

const double LEFT_X   = 150;
const double LEFT_Y   = 300;
const double RIGHT_X  = 450;
const double RIGHT_Y  = 300;
const double TOP_X    = 300;
const double TOP_Y    = 450;
const double BOTTOM_X = 300;
const double BOTTOM_Y = 150;
const double RADIUS   = 106;

//
double distance(double x1, double y1, double x2, double y2) {
	return hypot(x2 - x1, y2 - y1);
}

void mouse_moved(double x, double y) {
	// Is the mouse cursor over the left circle?
	if (distance(x, y, LEFT_X, LEFT_Y) < RADIUS)
		active_circle = Circle::Left;
	// Is the mouse cursor over the right circle?
	else if (distance(x, y, RIGHT_X, RIGHT_Y) < RADIUS)
		active_circle = Circle::Right;
	// Is the mouse cursor over the top circle?
	else if (distance(x, y, TOP_X, TOP_Y) < RADIUS)
		active_circle = Circle::Top;
	// Is the mouse cursor over the bottom circle?
	else if (distance(x, y, BOTTOM_X, BOTTOM_Y) < RADIUS)
		active_circle = Circle::Bottom;
	else
		active_circle = Circle::None;
	sgl::update_window();
}

void paint() {
	sgl::set_line_width(4);
	sgl::set_color(sgl::BLACK);
	// Draw the left circle
	sgl::draw_circle(LEFT_X, LEFT_Y, RADIUS);
	// Draw the right circle
	sgl::draw_circle(RIGHT_X, RIGHT_Y, RADIUS);
	// Draw the top circle
	sgl::draw_circle(TOP_X, TOP_Y, RADIUS);
	// Draw the Bottom circle
	sgl::draw_circle(BOTTOM_X, BOTTOM_Y, RADIUS);
	// Is the left circle active?
	if (active_circle == Circle::Left) {
		sgl::set_color(sgl::RED);
		sgl::fill_circle(LEFT_X, LEFT_Y, RADIUS - 1);
	}
	// Is the right circle active?
	else if (active_circle == Circle::Right) {
		sgl::set_color(sgl::BLUE);
		sgl::fill_circle(RIGHT_X, RIGHT_Y, RADIUS - 1);
	}
	// Is the top circle active?
	else if (active_circle == Circle::Top) {
		sgl::set_color(sgl::GREEN);
		sgl::fill_circle(TOP_X, TOP_Y, RADIUS - 1);
	}
	// Is the bottom circle active?
	else if (active_circle == Circle::Bottom) {
		sgl::set_color(sgl::YELLOW);
		sgl::fill_circle(BOTTOM_X, BOTTOM_Y, RADIUS - 1);
	}
}


int main() {
	sgl::create_window("Four Circles", 0, 600, 0, 600);
	sgl::set_paint_function(paint);
	sgl::set_mouse_moved_function(mouse_moved);
	sgl::run_window();
}
