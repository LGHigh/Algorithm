#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n, m, num;
bool IsEasy(vector<int>& res, int t) {
	int len = res.size();
	for (int i = len - 1; i >= len / 2; i--)if (res[i] == t) {
		int ok = 1;
		for (int j = len - 1, k = 1; j > i; j--, k++) {
			if (res[i - k] != res[j])ok = 0;
		}
		if (ok)return true;
	}
	return false;
}

void dfs(vector<int>res) {
	if (num == n) {
		int len = res.size();
		for (int i = 0; i < len; i++) {
			if (i && i % 4 == 0 && i % 64 != 0)cout << " " << (char)(res[i] + 'A');
			else if (i && i % 64 == 0)cout << endl << (char)(res[i] + 'A');
			else cout << (char)(res[i] + 'A');
		}
		cout<<endl<< len << endl;
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!IsEasy(res, i)) {
			num++; res.push_back(i); dfs(res); res.pop_back();
		}
		if (num == n)return;
	}
}

int main() {
	while (cin >> n >> m && (n || m)) {
		vector<int>res; num = 0;
		dfs(res);
	}
}