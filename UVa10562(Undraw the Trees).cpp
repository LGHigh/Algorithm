/*
对边界条件要谨慎处理
*/

#include <iostream>
#include <string>
#include <set>
#include <string.h>
using namespace std;

string a[210];
int now[210];

void solve(int row) {
	int ok = 0;
	for (int i = now[row]; i < 210; i++) {
		if (a[row - 1][i] == '-') while (a[row - 1][i] == '-') {
			ok = 1;
			if (a[row][i] != ' ' && a[row][i]!='\0') {
				cout << a[row][i] << "(";
				if (a[row + 1][i] == '|')solve(row + 3);
				cout << ")";
			}
			i++;
		}
		if (ok) { row[now] = i; return; }
	}
}

int main() {
	int cnt; cin >> cnt;
	string rb;
	getline(cin, rb);
	while (cnt--) {
		int i;
		memset(now, 0, sizeof(now));
		for (int i = 0; i < 210; i++)a[i].clear();
		for (i = 0;; i++) {
			getline(cin, a[i]);
			if (a[i] == "#") break;
		}
		for (int i = 0; i < 210; i++)a[i].resize(210);
		cout << "(";
		for (int i = 0; i < 210; i++)if (a[0][i] != ' ' && a[0][i] != '#' && a[0][i]!='\0') { cout << a[0][i] << "("; solve(3); cout << ")"; break; }
		cout << ")" << endl;
	}
	return 0;
}