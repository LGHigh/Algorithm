#include <stdio.h>

int a[1010], b[1010];

int main() {
	int n, cnt = 0;
	while (scanf_s("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++cnt);
		for (int i = 0; i < n; i++)scanf_s("%d", &a[i]);
		for (;;) {
			int A = 0, B = 0, t = 0;
			for (int i = 0; i < n; i++) { 
				if (scanf_s("%d", &b[i]) == 1 && !b[i])t++; 
				if (b[i] == a[i])A++;
			}
			if (t == n)break;
			for (int d = 1; d <= 9; d++) {
				int c1 = 0, c2 = 0;
				for (int k = 0; k < n; k++) {
					if (a[k] == d)c1++;
					if (b[k] == d)c2++;
				}
				c1 = c1 > c2 ? c2 : c1;
				B += c1;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}