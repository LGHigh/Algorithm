#include <stdio.h>
#include <string>
#include <cstring>

const int maxn = 10100;
int a[maxn][10];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)a[0][i] = 0;
	for (int i = 1; i < maxn; i++) {
		for (int k = 0; k < 10; k++)a[i][k] = a[i - 1][k];
		int x = i;
		do {
			a[i][x % 10]++;
		} while (x /= 10);
	}
	while (n--) {
		int t;
		scanf("%d", &t);
		for (int i = 0; i < 9; i++)printf("%d ", a[t][i]);
		printf("%d\n", a[t][9]);
	}
	return 0;
}