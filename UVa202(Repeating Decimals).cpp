#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y, tx, ty, cnt, test = 1;
	while (cin >> x) {
		cnt = 1;
		vector<int>d;
		vector<int>t;
		cin >> y;
		tx = x; ty = y;
		for (int i = 0; i < y + 1; i++) {
			t.push_back(0);
		}
		x = x % y;
		while (1) {
			if (x == 0)break;
			if (t[x])break;
			t[x] = cnt++;
			x *= 10;
			d.push_back(x / y);
			x = x % y;
		}

		//if (test++ != 1)printf("\n");
		printf("%d/%d = %d.", tx, ty, tx / ty);
		if (x%y == 0) {
			for (int i = 0; i < d.size(); i++) {
				printf("%d", d[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n\n");
		}
		else {
			for (int i = 0; i < t[x%y]-1; i++) {
				printf("%d", d[i]);
			}
			printf("(");
			if(cnt-1-t[x%y]<=50)
				for (int i = t[x%y]-1; i < cnt-1; i++) {
					printf("%d", d[i]);
				}
			else{
				for (int i = t[x%y]-1; i < 50; i++) {
					printf("%d", d[i]);
				}
				printf("...");
			}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n\n", cnt - t[x%y]);
		}
	}
}