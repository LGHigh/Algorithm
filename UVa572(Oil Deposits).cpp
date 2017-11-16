#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int cnt = 0;

void helper(string* pic, int n, int m, int i, int j) {
	pic[i][j] = '*';
	if (i - 1 >= 0) {
		if (pic[i - 1][j] == '@')helper(pic, n, m, i - 1, j);
		if (j - 1 >= 0 && pic[i - 1][j - 1] == '@')helper(pic, n, m, i - 1, j - 1);
		if (j + 1 < m && pic[i - 1][j + 1] == '@')helper(pic, n, m, i - 1, j + 1);
	}
	if (j - 1 >= 0 && pic[i][j - 1] == '@')helper(pic, n, m, i, j - 1);
	if (j + 1 < m && pic[i][j + 1] == '@')helper(pic, n, m, i, j + 1);
	if (i + 1 < n) {
		if (pic[i + 1][j] == '@')helper(pic, n, m, i + 1, j);
		if (j - 1 >= 0 && pic[i + 1][j - 1] == '@')helper(pic, n, m, i + 1, j - 1);
		if (j + 1 < m && pic[i + 1][j + 1] == '@')helper(pic, n, m, i + 1, j + 1);
	}
}

void solve(string* pic,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == '@') { cnt++; helper(pic, n, m, i, j); }
		}
	}
}

int main() {
	string pic[110];
	int n, m;
	while (cin >> n >> m && n) {
		for (int i = 0; i < n; i++) {
			cin >> pic[i];
		}
		solve(pic, n, m);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}