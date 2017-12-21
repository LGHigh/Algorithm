#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int m, n;
int num[110][110];
int Next[110][110];
int dp[110][110];

int d(int i, int j) {
	int& ans = dp[i][j];
	if (ans > 0)return ans;
	if (j == n - 1) {
		ans = num[i][j];
		return ans;
	}
	int row[3] = { i,i - 1,i + 1 };
	if (i == 0)row[1] = m - 1;
	if (i == m - 1)row[2] = 0;
	sort(row, row + 3);
	ans = 0;
	for (int k = 0; k < 3; k++) {
		int v = d(row[k],j + 1) + num[i][j];
		if (ans==0 || v < ans) { ans = v; Next[i][j] = row[k]; }
	}
	return ans;
}

int main() {

	while (cin >> m >> n) {
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		memset(Next, 0, sizeof(Next));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> num[i][j];
		for (int i = 0; i < m; i++) {
			d(i, 0);
		}
		int wh = 0, min = dp[0][0];
		for (int i = 1; i < m; i++) {
			if (dp[i][0] < min)wh = i;
		}
		cout << wh + 1;
		for (int i = Next[wh][0], j = 1; j < n; i = Next[i][j], j++) {
			cout << " " << i + 1;
		}
		cout << endl << dp[wh][0] << endl;
	}
	return 0;
}