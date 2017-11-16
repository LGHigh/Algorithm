#include <stdio.h>
int main() {
	double a, b, c;
	scanf_s("%lf%lf%lf", &a, &b, &c);
	a = (a + b + c) / 3;
	printf("%.3f\n",a);
	return 0;
}