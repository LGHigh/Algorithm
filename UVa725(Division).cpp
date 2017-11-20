#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n, kase = 0;;
	while (cin >> n && n) {
		int a[10];
		int have = 0;
		if (kase++)cout << endl;
		for (int i = 1000; i*n < 100000; i++) {
			if (i*n < 10000)continue;
			memset(a, 1, sizeof(a));
			int t1 = i*n, t2 = i;
			int ok = 0;
			if (t2 < 10000) { a[0] = 0; ok = 1; }
			while (t1 != 0) {
				a[t1 % 10] = 0;
				t1 /= 10;
			}
			while (t2 != 0) {
				a[t2 % 10] = 0;
				t2 /= 10;
			}
			int sum = 0;
			for (int i = 0; i < 10; i++)sum += a[i];
			if (!sum) {
				have = 1;
				cout << i*n << " / ";
				if (ok)cout << "0";
				cout << i << " = " << n << endl;
			}
		}
		if (!have)cout << "There are no solutions for " << n << "." << endl;
	}
	return 0;