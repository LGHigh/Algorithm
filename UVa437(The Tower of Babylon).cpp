#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int tr[40][3];
int dp[40][3];
int G[100][100];
int n;

bool Less(int i, int j, int m, int n) {
	int a = (j + 1) % 3, b = (j + 2) % 3;
	int x = (n + 1) % 3, y = (n + 2) % 3;
	if (tr[i][a] < tr[m][x] && tr[i][b] < tr[m][y])return true;
	if (tr[i][a] < tr[m][y] && tr[i][b] < tr[m][x])return true;
	return false;
}

int d(int i) {
	int& ans = dp[i/3][i%3];
	if (ans > 0)return ans;
	ans = tr[i / 3][i % 3];
	for (int k = 0; k < 3 * n; k++) {
		if (G[i][k])ans = max(ans, d(k) + tr[i / 3][i % 3]);
	}
	return ans;
}

int main() {
	int kase = 0;
	while (cin >> n && n) {
		int res = 0;
		memset(dp, 0, sizeof(dp));
		memset(tr, 0, sizeof(tr));
		memset(G, 0, sizeof(G));
		for (int i = 0; i < n; i++) {
			cin >> tr[i][0] >> tr[i][1] >> tr[i][2];
		}
		for (int i = 0; i < 3 * n; i++) {
			int x = i / 3, y = i % 3;
			for (int j = 0; j < 3 * n; j++) {
				if (Less(x, y, j / 3, j % 3))G[i][j] = 1;
			}
		}

		for (int i = 0; i < 3 * n; i++)
			d(i);
		for (int i = 0; i < 3 * n; i++)res = max(res,dp[i / 3][i % 3]);
		cout << "Case " << ++kase << ": maximum height = " << res << endl;
	}
}