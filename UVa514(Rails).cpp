#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		int t;
		while (cin >> t && t) {
			stack<int>B, C;
			B.push(t);
			for (int i = 1; i < n; i++) {
				int t; cin >> t;
				B.push(t);
			}
			int ok = 1;
			for (int i = n; i >= 1; i--) {
				while (!B.empty()) {
					if (B.top() != i && (C.empty() || C.top() != i)) {
						C.push(B.top()); B.pop();
					}
					else if (B.top() == i)  break;
					else break;
				}
				if (B.empty()) {
					if (C.top() == i)C.pop();
					else { ok = 0; break; }
				}
				else {
					if (B.top() == i)B.pop();
					else if (C.empty() || C.top()!=i) { ok = 0; break; }
					else C.pop();
				}
			}
			if (!ok)cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		cout << endl;
	}
	return 0;
}