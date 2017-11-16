#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = n; i > 0; i--) {
		for (int j = n - i; j > 0; j--)
			printf(" ");
		for (int j = i * 2 - 1; j > 0; j--)
			printf("#");
		printf("\n");
	}
	return 0;
}