#include <stdio.h>
#include <string>
#include <cstring>
const int maxn = 100;

int main() {
	int n;
	scanf("%d",&n);
	while (n--) {
		char a[maxn];
		scanf("%s", a);
		int len = strlen(a);
		int cnt = 0, sum = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] == 'O')
				sum += ++cnt;
			else cnt = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}