#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int n, m;
map<string, int>IDcache;
vector<string>Strcache;
vector<int>cache;

struct node {
	int x; int y;
	node(int x, int y) :x(x), y(y) {}
	bool operator < (const node& r) const { return x<r.x || x == r.x && y<r.y; }
};
map<node, int>Data;

size_t ID(string x) {
	if (IDcache.count(x))return IDcache[x];
	Strcache.push_back(x);
	return IDcache[x] = Strcache.size()-1;
}



void read() {
	string str = "";
	char ch = getchar();
	for (int i = 0; i < n; i++) {
		for (;;) {
			ch = getchar();
			if (ch == '\r' || ch == '\n') {
				if (!str.empty())cache.push_back(ID(str));
				str.clear(); break;
			}
			if (ch != ',')str += ch;
			else { cache.push_back(ID(str)); str.clear(); }
		}
	}
}
void solve() {
	for (int j = 0; j < m; j++) {
		for (int k = j + 1; k < m; k++) {
			Data.clear();
			for (int i = 0; i < n; i++) {
				node p(cache[i*m + j], cache[i*m + k]);
				if (!Data.count(p))Data[p] = i;
				else {
					cout << "NO" << endl;
					cout << Data[p] + 1 << " " << i + 1 << endl;
					cout << j + 1 << " " << k + 1 << endl;
					return;
				}
			}
		}
	}
	cout << "YES"<<endl;
}

int main() {
	//ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		read();
		solve();
		cache.clear();
		IDcache.clear(); Strcache.clear();
	}
	return 0;
}