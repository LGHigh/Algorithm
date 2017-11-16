#include <iostream>
#include <string>
#include <set>
#include <string.h>
using namespace std;
int a[105][105];
int topo[105], t;
int c[105], n, m;
bool dfs(int u) {
	c[u] = -1;
	for (int v = 1; v <= n; v++) if(a[u][v]){
		if (c[v] < 0)return false;
		else if (!c[v] && !dfs(v))return false;
	}
	c[u] = 1; topo[--t] = u;
	return true;
}

bool toposort() {
	t = n;
	memset(c, 0, sizeof(c));
	for (int u = 1; u <= n; u++)
		if(!c[u])
			if (!dfs(u))return false;
	return true;
}

int main() {
	
	while (cin >> n >> m && (n || m)) {
		memset(a, 0, sizeof(a));
		int x, y;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		if (toposort()) {
			for (int i = 0; i < n - 1; i++)
				cout << topo[i] << " ";
			cout << topo[n - 1] << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}