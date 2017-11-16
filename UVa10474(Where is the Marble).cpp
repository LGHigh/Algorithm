#include <iostream>  
#include <cstdio>  
#include <string>  
#include <vector>
#include <cstring> 
#include <algorithm>
using namespace std;

int main() {
	int n, q, kase = 0;
	cin >> n >> q;
	while (n) {
		printf("CASE# %d:\n", ++kase);
		vector<int>m;
		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			m.push_back(t);
		}
		sort(m.begin(), m.end());
		for (int i = 0; i < q; i++) {
			int x, loc = 0; cin >> x;
			for (int j = 0; j < n; j++) {
				if (m[j] == x) {
					loc = j + 1; break;
				}
				else if (m[j] > x)break;
			}
			if (loc)printf("%d found at %d\n", x, loc);
			else printf("%d not found\n", x);
		}
		cin >> n >> q;
	}
}