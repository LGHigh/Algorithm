#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

char a[] = { 'A','C','G','T' };

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num, len, sum = 0;
		vector<string>DNA;
		string res = "";
		scanf("%d%d", &num, &len);

		for (int i = 0; i < num; i++) {
			string tmp;
			cin >> tmp;
			DNA.push_back(tmp);
		}
		for (int i = 0; i < len; i++) {
			int cnt[] = { 0,0,0,0 };
			for (int j = 0; j < num; j++) {
				for (int k = 0; k < 4; k++) {
					if (DNA[j][i] == a[k]) {
						cnt[k]++;
						break;
					}
				}
			}
			int max = 0;
			for (int t = 1; t < 4; t++) {
				if (cnt[t] > cnt[max])max = t;
			}
			for (int t = 0; t < 4; t++) {
				if (t != max)sum += cnt[t];
			}
			res += a[max];
		}
		cout << res << endl;
		cout << sum << endl;
	}
}