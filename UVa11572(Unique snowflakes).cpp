#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000000 + 5;
int A[maxn];

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		set<int>s;
		int L = 0, R = 0, ans = 0;
		while (R < n) {
			while (R < n && !s.count(A[R]))s.insert(A[R++]);
			ans = max(ans, R - L);
			s.erase(A[L++]);
		}
		cout << ans << endl;
	}
}