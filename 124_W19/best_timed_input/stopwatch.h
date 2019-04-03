#include <ctime>

class Stopwatch {
	clock_t start_time;
	clock_t end_time;
public:
	void start();
	void stop();
	double elapsed();
};