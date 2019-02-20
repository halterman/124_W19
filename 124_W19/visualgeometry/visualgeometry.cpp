// visualgeometry.cpp
// Created 2/20/2019 2:08:45 PM

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <memory>

#ifdef __APPLE__
#include "sgl.hpp"  
#else
#include <GL/sgl.hpp> 
#endif
#include "geometry.h"


/***********************************************
*  GeoPoint code
***********************************************/
class GeoPoint : public sgl::GraphicalObject {
protected:
	sgl::Color color;
public:
	GeoPoint(double x, double y, const sgl::Color& c) :
		sgl::GraphicalObject(x, y, 4, 4), color(c) {
		set_cursor(sgl::CursorShape::Crosshair);
	}

	~GeoPoint() {}

	double get_x() const {
		return left + width / 2;
	}

	double get_y() const {
		return bottom + height / 2;
	}

	void paint() const override {
		sgl::set_color(color);
		sgl::fill_circle(left + width / 2, bottom + height / 2, 2);
		if (mouse_over)
			sgl::draw_circle(left + width / 2, bottom + height / 2, 4);
	}

	void mouse_pressed(double x, double y, sgl::MouseButton) override {
		std::cout << "x=" << x << "  y=" << y << std::endl;
	}

};


/**************************************************
*  GeometryWindow code
**************************************************/

const double MIN_X = -100.0,
MAX_X = 100.0,
MIN_Y = -100.0,
MAX_Y = 100.0;

class GeometryWindow : public sgl::ObjectWindow {
protected:
	GeoPoint *pt1,
		*pt2,
		*pt3,
		*pt4,
		*pt_inter;

	double xi,
		yi;

	sgl::Point current_mouse_coord;

	//  Currently selected graphical object, null if none
	sgl::CursorShape normal_cursor,
		active_cursor;


	bool making_vertical;
	bool making_horizonal;
public:
	GeometryWindow(const char *title, int left, int top, int width, int height,
		double min_x, double max_x, double min_y, double max_y) :
		sgl::ObjectWindow(title, left, top, width, height, min_x, max_x, min_y, max_y),
		pt1(nullptr), pt2(nullptr), pt3(nullptr), pt4(nullptr), pt_inter(nullptr),
		xi(INFINITY), yi(INFINITY),
		current_mouse_coord({ 0.0, 0.0 }),
		normal_cursor(get_cursor()),
		active_cursor(sgl::CursorShape::Crosshair),
		making_vertical(false), making_horizonal(false) {}

	//  Removes the points from the window and 
	//  there corresponding graphical objects
	void clear() {
		//  Remove the graphical objects from the window
		remove_all();
		//  Set all the points to null
		pt1 = pt2 = pt3 = pt4 = pt_inter = nullptr;
		repaint();
	}


	void draw_extended_line(GeoPoint *start_point, GeoPoint *end_point) {
		double m = slope(start_point->get_x(), start_point->get_y(),
			end_point->get_x(), end_point->get_y()),
			b = intercept(start_point->get_x(), start_point->get_y(),
				end_point->get_x(), end_point->get_y()),
			new_x1, new_y1, new_x2, new_y2;
		if (m == INFINITY) {
			new_x1 = new_x2 = start_point->get_x();
			new_y1 = MIN_Y;
			new_y2 = MAX_Y;
		}
		else if (m >= -1.0 && m <= 1.0) {
			intersection(m, b, INFINITY, MIN_X, new_x1, new_y1);
			intersection(m, b, INFINITY, MAX_X, new_x2, new_y2);
		}
		else {
			intersection(m, b, 0, MIN_Y, new_x1, new_y1);
			intersection(m, b, 0, MAX_Y, new_x2, new_y2);
		}
		sgl::set_line_width(2.0);
		sgl::draw_line(new_x1, new_y1, new_x2, new_y2);
		sgl::set_line_width(1.0);
	}

	void paint() override {
		draw_axes(10.0, 10.0);   //  Draw axes
		sgl::set_color(sgl::DARK_GRAY);

		std::ostringstream oss;

		if (making_vertical) {
			sgl::set_color(sgl::BLACK);
			sgl::draw_dashed_line(current_mouse_coord.x, MIN_Y, current_mouse_coord.x, MAX_Y);
		}
		else if (making_horizonal) {
			sgl::set_color(sgl::BLACK);
			sgl::draw_dashed_line(MIN_X, current_mouse_coord.y, MAX_X, current_mouse_coord.y);
		}
		sgl::set_color(sgl::LIGHT_GRAY);
		if (pt1) {  //  First point exists
			sgl::set_color(sgl::DARK_GREEN);  //  
			print_point(pt1->get_x(), pt1->get_y(), oss);
			sgl::draw_text(oss.str().c_str(),
				pt1->get_x() + 5, pt1->get_y() + 5, 10);
			oss.str(std::string{});  // Clear the stream buffer
			if (pt2) {
				//  First line ready to render
				draw_extended_line(pt1, pt2);
				print_line(slope(pt1->get_x(), pt1->get_y(),
					pt2->get_x(), pt2->get_y()),
					intercept(pt1->get_x(), pt1->get_y(),
						pt2->get_x(), pt2->get_y()),
					oss);
				sgl::draw_text(oss.str().c_str(), MIN_X + 10, MIN_Y + 15, 10);
				oss.str(std::string{});  // Clear the stream buffer
				print_point(pt2->get_x(), pt2->get_y(), oss);
				sgl::draw_text(oss.str().c_str(), pt2->get_x() + 5, pt2->get_y() + 5, 10);
				oss.str(std::string{});  // Clear the stream buffer
				if (pt3) {
					sgl::set_color(sgl::BLUE);  //  Blue
					print_point(pt3->get_x(), pt3->get_y(), oss);
					sgl::draw_text(oss.str().c_str(), pt3->get_x() + 5, pt3->get_y() + 5, 10);
					oss.str(std::string{});  // Clear the stream buffer
					if (pt4) {
						//  Second line ready to render
						draw_extended_line(pt3, pt4);
						print_line(slope(pt3->get_x(), pt3->get_y(),
							pt4->get_x(), pt4->get_y()),
							intercept(pt3->get_x(), pt3->get_y(),
								pt4->get_x(), pt4->get_y()),
							oss);
						sgl::draw_text(oss.str().c_str(), MIN_X + 10, MIN_Y + 25, 10);
						oss.str(std::string{});  // Clear the stream buffer
						print_point(pt4->get_x(), pt4->get_y(), oss);
						sgl::draw_text(oss.str().c_str(), pt4->get_x() + 5, pt4->get_y() + 5, 10);
						oss.str(std::string{});  // Clear the stream buffer
						double slope1 = slope(pt1->get_x(), pt1->get_y(),
							pt2->get_x(), pt2->get_y()),
							intercept1 = intercept(pt1->get_x(),
								pt1->get_y(),
								pt2->get_x(),
								pt2->get_y()),
							slope2 = slope(pt3->get_x(), pt3->get_y(),
								pt4->get_x(), pt4->get_y()),
							intercept2 = intercept(pt3->get_x(),
								pt3->get_y(),
								pt4->get_x(),
								pt4->get_y());
						//  Compute intersection, if possible
						intersection(slope1, intercept1, slope2, intercept2, xi, yi);
						//  Draw the point in the window
						sgl::set_color(sgl::RED);  //  Red
						//draw_point(xi, yi);
						sgl::fill_circle(xi, yi, 2);
						print_point(xi, yi, oss);
						sgl::draw_text(oss.str().c_str(), xi + 5, yi + 5, 10);
						oss.str(std::string{});  // Clear the stream buffer
					}
				}
			}
		}
	}


	void resized(int w, int h) override {
		if (w != h) { //  Force window to be square
			(w > h) ? w = h : h = w;
			set_window_size(w, h);
		}
		sgl::Window::resized(w, h);  //  Base class method does the rest
	}


	void mouse_dragged(double x, double y) override {
		sgl::ObjectWindow::mouse_dragged(x, y);

		if (get_key_modifiers() == sgl::KeyModifier::ALT_KEY)
			std::cout << "Alt key depressed" << '\n';
	}

	void mouse_pressed(double x, double y, sgl::MouseButton button) override {
		if (button == sgl::MouseButton::Left) {
			if (!pt1) {
				pt1 = add<GeoPoint>(x - 2, y - 2, sgl::DARK_GREEN);
				//  Make a vertical line?
				if (making_vertical) {
					pt2 = add<GeoPoint>(x - 2, -2.0, sgl::DARK_GREEN);
					making_vertical = false;
				}
				//  Make a horizontal line?
				else if (making_horizonal) {
					pt2 = add<GeoPoint>(-2.0, y - 2, sgl::DARK_GREEN);
					making_horizonal = false;
				}
			}
			else if (!pt2)
				pt2 = add<GeoPoint>(x - 2, y - 2, sgl::DARK_GREEN);
			else if (!pt3) {
				pt3 = add<GeoPoint>(x - 2, y - 2, sgl::BLUE);
				//  Make a vertical line?
				if (making_vertical) {
					pt4 = add<GeoPoint>(x - 2, -2.0, sgl::BLUE);
					making_vertical = false;
				}
				//  Make a horizontal line?
				else if (making_horizonal) {
					pt4 = add<GeoPoint>(-2.0, y - 2, sgl::BLUE);
					making_horizonal = false;
				}
			}
			else if (!pt4)
				pt4 = add<GeoPoint>(x - 2, y - 2, sgl::BLUE);
		}
		sgl::ObjectWindow::mouse_pressed(x, y, button);
		repaint();
	}

	void mouse_moved(double x, double y) override {
		if (making_vertical || making_horizonal) {
			current_mouse_coord.x = x;
			current_mouse_coord.y = y;
			repaint();
		}
		sgl::ObjectWindow::mouse_moved(x, y);
	}

	void key_pressed(int k, double x, double y) override {
		current_mouse_coord.x = x;
		current_mouse_coord.y = y;
		switch (k) {
			case 'V':    // Capital V turns off vertical line mode
				making_vertical = false;
				break;
			case 'v':    // Lowercase V turns on vertical line mode
				making_vertical = true;
				break;
			case 'H':    // Capital H turns off horizontal line mode
				making_horizonal = false;
				break;
			case 'h':    // Lowercase H turns on horizontal line mode
				making_horizonal = true;
				break;
			case 27:     //  Esc key removes all the points 
				clear();
				break;
		}
		//cout << "key: " << k << "  ( " << static_cast<char>(k) << ")" << endl;
		sgl::ObjectWindow::key_pressed(k, x, y);
		repaint();
	}

	virtual void quit() {
		exit(0);
	}

};



int main() {
	sgl::run<GeometryWindow>("Visual Geometry", 100, 100, 600, 600,
		MIN_X, MAX_X, MIN_Y, MAX_Y);
}