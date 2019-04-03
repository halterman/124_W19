#include "stopwatch.h"
#include <ctime>

clock_t start_time, end_time;

void start_clock() {
	start_time = clock();
}

void stop_clock() {
	end_time = clock();
}

double elapsed_clock() {
	return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}
