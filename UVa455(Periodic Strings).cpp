#include <stdio.h>
#include <string>
#include <cstring>

const int maxn = 120;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char s[maxn];
		int t[maxn]; t[0] = 0;
		int min = 0;
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 1; i < len; i++) {
			if (t[i - 1] != 0 && s[t[i - 1]] == s[i])t[i] = t[i - 1] + 1;
			else if (s[i] == s[0])t[i] = 1;
			else t[i] = 0;
		}
		int ok = 0;
		if(t[len-1])
			for (int i = len - 1; i >= 0; i--) {
				if (t[i] == 1) {
					if (t[len - 1] % i == 0) {
						printf("%d\n", i);
						ok = 1;
					}
					break; 
				}
			}
		if (!ok)printf("%d\n", len);
		if(n)printf("\n");
	}
}