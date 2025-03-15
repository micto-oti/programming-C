#include <math.h>

double perimeter(double a, double b, double c) {
	double p;
	return p = a + b + c;
}

double calculateArea(double a, double b, double c) {
	double sp = (a + b + c) / 2;
	return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
}
