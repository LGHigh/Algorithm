#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int kase = 0;

bool IsPrime(int t) {
	for (int i = 2; i*i <= t; i++) {
		if (t%i == 0)return false;
	}
	return true;
}

void dfs(int cur, int* sig, int tot, vector<int>res) {
	int ok = 0;
	res.push_back(cur);
	for (int i = 1; i <= tot; i++) {
		if (sig[i]) {
			ok = 1;
			if (IsPrime(cur + i)) {
				sig[i] = 0; dfs(i, sig, tot, res); sig[i] = 1;
			}
		}
	}
	if (!ok) if (IsPrime(1 + res[tot - 1])) {
		for (int i = 0; i < tot - 1; i++)cout << res[i] << " ";
		cout << res[tot - 1] << endl;
	}
}

int main() {
	int tot;
	int sig[20];
	vector<int>res;
	while (cin >> tot) {
		memset(sig, 1, sizeof(sig));
		sig[1] = 0;
		if (kase)cout << endl;
		cout << "Case " << ++kase << ":\n";
		dfs(1, sig, tot,res);
	}
}