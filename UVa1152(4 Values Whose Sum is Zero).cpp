#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
	long long num;
	int cnt;
	Node(long long num, int cnt) :num(num), cnt(cnt) {}
};


int main() {
	int Kase; cin >> Kase;
	int kase = 0;
	while (kase!=Kase) {
		vector<long long> x, y, z, w;
		if (kase)cout << endl; kase++;
		vector<long long>a, b;
		long long n; cin >> n;
		for (long long i = 0; i < n; i++) {
			long long x1, y1, z1, w1; cin >> x1 >> y1 >> z1 >> w1;
			x.push_back(x1); y.push_back(y1); z.push_back(z1); w.push_back(w1);
		}
		for (long long i = 0; i < n; i++) {
			for (long long j = 0; j < n; j++) {
				a.push_back(x[i] + y[j]); b.push_back(z[i] + w[j]);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());

		int t = n*n;
		vector<Node>p, q;
		p.push_back(Node(a[t - 1], 1)); q.push_back(Node(b[t - 1], 1));
		a.pop_back(); b.pop_back();
		for (int i = t - 2; i >= 0; i--) {
			if (p.back().num == a[i]) {
				p.back().cnt++; a.pop_back();
			}
			else {
				p.push_back(Node(a[i], 1)); a.pop_back();
			}
			if (q.back().num == b[i]) {
				q.back().cnt++; b.pop_back();
			}
			else {
				q.push_back(Node(b[i], 1)); b.pop_back();
			}
		}
		long long num = 0; 
		while(1) {
			if (p.empty() || q.empty())break;
			long long x1 = p.back().num; long long x2 = q.back().num;
			if (x1 + x2 == 0) { num += p.back().cnt*q.back().cnt; p.pop_back(); q.pop_back(); }
			else if (x1 + x2 > 0) { q.pop_back(); }
			else { p.pop_back(); }
		}
		cout << num << endl ;
	}
	return 0;
}