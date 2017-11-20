#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int a[10][10], b[10];
int Max = 8, Maxn = 0;
vector<int>best;

void dfs(vector<int>tmp, int width) {
	int len = tmp.size();
	int t = width;
	if (len == Maxn) { if (width < Max) { best = tmp; Max = width; } }
	else for (int j = 0; j < Maxn; j++) {
		if (!b[j]) {
			for (int i = 0; i < len; i++) {
				if (a[tmp[i]][j]) {
					if (len - i >= Max)return;
					if (len - i > width)width = len - i;
				}
			}
			tmp.push_back(j); b[j] = 1; dfs(tmp, width);
			tmp.pop_back(); b[j] = 0; width = t;
		}
	}
}

int main() {
	string str;
	while (cin >> str && str != "#") {
		int len = str.length();
		string str1 = "", str2 = ""; int node = 0;
		memset(b, 0, sizeof(b));
		memset(a, 0, sizeof(a));
		best.clear(); Max = 8; Maxn = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == ':')node = 1;
			else if (str[i] == ';') {
				int sublen = str2.length();
				for (int j = 0; j < sublen; j++) {
					a[str1[0] - 'A'][str2[j] - 'A'] = 1; a[str2[j] - 'A'][str1[0] - 'A'] = 1;
					if (Maxn < str1[0] - 'A')Maxn = str1[0] - 'A' + 1;
					if (Maxn < str2[j] - 'A')Maxn = str2[j] - 'A' + 1;
				}
				str1 = str2 = "";
				node = 0;
			}
			else if (!node)str1 += str[i];
			else str2 += str[i];
		}
		int sublen = str2.length();
		for (int j = 0; j < sublen; j++) {
			a[str1[0] - 'A'][str2[j] - 'A'] = 1; a[str2[j] - 'A'][str1[0] - 'A'] = 1;
			if (Maxn < str1[0] - 'A' + 1)Maxn = str1[0] - 'A' + 1;
			if (Maxn < str2[j] - 'A' + 1)Maxn = str2[j] - 'A' + 1;
		}
		vector<int> tmp;
		dfs(tmp, 0);
		for (int i = 0; i < Maxn; i++)cout << (char)('A' + best[i]) << " ";
		cout << "-> " << Max << endl;
	}
	return 0;
}