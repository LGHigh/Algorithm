#include <stdio.h>

int main() {
	for (int i = 100; i < 1000; i++) {
		int a, b, c;
		a = i % 10;
		b = i % 100 / 10;
		c = i / 100;
		if (a*a*a + b*b*b + c*c*c == i) printf("%d\n", i);
	}
	return 0;
}