#include <stdio.h>
#include <string>
#include <cstring>

const int maxn = 110;
char name[] = "CNOH";


int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num[] = { 0,0,0,0 };
		char s[maxn];
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (isalpha(s[i])) {
				int tmp=-1;
				for (int k = 0; k < 4; k++) {
					if (name[k] == s[i])
						tmp = k;
				}
				int sum = 0;
				if(isdigit(s[i + 1]))
					while (isdigit(s[i + 1])) {
						i++;
						sum = sum * 10 + s[i]-'0';
					}
				else sum = 1;
				num[tmp] += sum;
			}
		}
		printf("%.3f\n", num[0] * 12.01 + num[1] * 14.01 + num[2] * 16.00 + num[3] * 1.008);
	}
	return 0;
}