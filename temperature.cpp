#include <stdio.h>

int main() {
	double f, c;
	scanf_s("%lf", &f);
	printf("%.3f", 5 * (f - 32.0) / 9);
	return 0;
}
