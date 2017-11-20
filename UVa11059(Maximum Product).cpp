#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, kase = 0;
	while (cin >> n) {
		//if (kase++)cout << endl;
		long long max = 0;
		vector<int> num;
		for (int i = 0; i < n; i++) { int x; cin >> x; num.push_back(x); }
		for (int i = 0; i < n; i++) {
			long long tot = 1;
			for (int j = i; j < n; j++) {
				tot *= num[j];
				if (tot > max)max = tot;
			}
		}
		cout << "Case #" << ++kase << ": " << "The maximum product is " << max << "."<<endl;
		cout << endl;
	}
	return 0;
}