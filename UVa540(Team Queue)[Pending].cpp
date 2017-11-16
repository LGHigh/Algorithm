#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, kase = 0;
	while (cin >> n && n) {
		vector<set<int>> a;
		queue<int>q; vector<int>v;
		vector<queue<int>>qa;
		qa.resize(n); v.resize(n);
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			set<int> tmp;
			for (int i = 0; i < num; i++) {
				int t; cin >> t;
				tmp.insert(t);
			}
			a.push_back(tmp);
		}
		string cmd;
		cout << "Scenario #" << ++kase << endl;
		while (cin >> cmd && cmd != "STOP") {
			if (cmd[0] == 'E') {
				cin >> n;
				int len = a.size();
				for (int i = 0; i < len; i++) {
					if (a[i].find(n) != a[i].end()) {
						qa[i].push(n);
						if (v[i] == 0) {
							v[i] = 1; q.push(i);
						}
					}
				}
			}
			else {
				int i = q.front();
				cout << qa[i].front() << endl;
				qa[i].pop();
				if (qa[i].empty()) { q.pop(); v[i] = 0; }
			}
		}
		cout<<endl;
	}
}