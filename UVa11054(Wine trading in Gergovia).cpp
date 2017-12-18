#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		long long sum = 0, tmp = 0;
		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			tmp += t;
			sum += abs(tmp);
		}
		cout << sum << endl;
	}
}