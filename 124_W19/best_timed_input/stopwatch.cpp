#include "stopwatch.h"

void Stopwatch::start() {
	start_time = clock();
}

void Stopwatch::stop() {
	end_time = clock();
}

double Stopwatch::elapsed() {
	return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}
