#include <stdio.h>
#include <string>

char a[110];

int less(const char *s, int p, int q) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[(p + i) % n] != s[q + i] % n)return s[(p + i) % n] < s[q + i] % n;
	}
	return 0;
}

int main() {
	int T;
	char s[110];
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%s", s);
		int n = strlen(s);
		int ans = 0;
		for (int i = 1; i < n; i++)
			if (less(s, i, ans))ans = i;
		for (int i = 0; i < n; i++)
			putchar(s[(i + ans) % n]);
		putchar('\n');
	}
	return 0;
}