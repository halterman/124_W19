double square_root(double number) {
	double root = 1;
	if (number >= 0.0) {
		while (root*root - number > 0.000000001 || root * root - number < -0.000000001) {
			root = (root + number / root) / 2;
		}
		return root;
	}
	else
		return 0.0;
}