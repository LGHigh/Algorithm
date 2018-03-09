#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	bool a[1000][1010];
	string str;
	int n; cin >> n;
	while (n--) {
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j <= len; j++) {
				int x = i; int y = j;
				bool pali = true;
				while (y > x) {
					if (str[x] != str[y - 1]) { pali = false; break; }
					y--; x++;
				}
				a[i][j] = pali;
			}
		}
		int d[1000];
		d[0] = 1;
		for (int i = 1; i < len; i++) {
			d[i] = d[i - 1] + 1;
			for (int j = 1; j <= i; j++) {
				if (a[i - j][i + 1]) {
					if (i - j)
						d[i] = min(d[i], d[i - j - 1] + 1);
					else
						d[i] = min(d[i], 1);
				}
			}
		}
		cout << d[len - 1] << endl;
	}
	return 0;
}