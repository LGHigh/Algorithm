#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int has_train[300][60][2];
int dp[300][60];
int t[60];
int n, T;

void solver() {
	for(int i=T-1;i>=0;i--)
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i + 1][j] + 1;
			if (j < n && has_train[i][j][0] && i + t[j] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
			if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
		}
}

int main() {
	int kase = 0;
	while (cin >> n && n) {
		memset(has_train, 0, sizeof(has_train));
		cin >> T;
		for (int i = 1; i <= n - 1; i++)dp[T][i] = 500;
		dp[T][n] = 0;
		for (int i = 1; i <= n - 1; i++) cin >> t[i];
		int M1, M2;
		cin >> M1;
		for (int i = 0; i < M1; i++) {
			int tmp; cin >> tmp;
			has_train[tmp][1][0] = 1;
			for (int i = 1; i <= n - 1; i++) {
				tmp += t[i];
				has_train[tmp][i + 1][0] = 1;
			}
		}
		cin >> M2;
		for (int i = 0; i < M2; i++) {
			int tmp; cin >> tmp;
			has_train[tmp][n][1] = 1;
			for (int i = n - 1; i >= 1; i--) {
				tmp += t[i];
				has_train[tmp][i][1] = 1;
			}
		}
		solver();
		cout << "Case Number " << ++kase << ": ";
		if (dp[0][1] >= 500)cout << "impossible\n";
		else cout << dp[0][1] << endl;
	}
	return 0;
}