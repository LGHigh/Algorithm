#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf_s("%d", &n);
	printf("%f\n%f\n", cos(n / 180.0 * 3.1415926), sin(n / 180.0 * 3.1415926));
	n=getchar();
	return 0;
}