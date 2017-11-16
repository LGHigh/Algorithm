#include <stdio.h>

int a[100010];

int main() {
	for (int i = 0; i <= 100000; i++)a[i] = 0;
	for (int i = 1; i <= 100000; i++) {
		int x=i, y=i;
		while (x > 0) { y += x % 10; x /= 10; }
		if (y<100010 && a[y] == 0 || i < a[y])a[y] = i;
	}
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf_s("%d", &t);
		if (a[t] != 0)printf("%d\n", a[t]);
		else printf("0\n");
	}
	return 0;
}