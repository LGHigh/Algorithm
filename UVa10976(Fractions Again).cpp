#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int>res;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (n*i % (i - n) == 0) {
				res.push_back(n*i / (i - n)); res.push_back(i);
			}
		}
		int len = res.size();
		cout << len / 2 << endl;
		for (int i = 0; i < len; i += 2) {
			cout << "1/" << n << " = 1/" << res[i] << " + 1/" << res[i + 1] << endl;
		}
	}
}