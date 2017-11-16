#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
int main() {
	int row, col, cnt = 0;
	scanf("%d", &row);
	while (row != 0) {
		scanf("%d", &col);
		char** a = new char*[row];
		for (int i = 0; i < row; i++) {
			a[i] = new char[col];
			scanf("%s", a[i]);
		}

		vector<string> rres;
		vector<string> cres;
		for (int i = 0; i < row;i++) {
			for (int j = 0; j < col; j++) {
				int cok = 0, rok = 0;
				if (a[i][j]!='*' && (j == 0 || a[i][j-1]=='*')) {
					string tmp = "";
					int y = 0;
					while (y + j < col && a[i][y + j] != '*') {
						tmp += a[i][y + j];
						y++;
					}
					cres.push_back(tmp);
					cok = 1;
				}
				if (a[i][j] != '*' && (i == 0 || a[i - 1][j] == '*')) {
					string tmp = "";
					int x = 0;
					while (x + i < row && a[i + x][j] != '*') { tmp += a[i + x][j]; x++; }
					rres.push_back(tmp);
					rok = 1;
				}
				if (cok && !rok)rres.push_back("\0");
				if (!cok && rok)cres.push_back("\0");
			}
		}
		if (cnt != 0)printf("\n");
		cout << "puzzle #" << ++cnt << ":" << endl;
		int len = rres.size();
		cout << "Across" << endl;
		for (int i = 0; i < len; i++) {
			if (cres[i] != "\0") {
				printf("%3d", i + 1);
				cout << "." << cres[i] << endl;
			}
		}
		cout << "Down" << endl;
		for (int i = 0; i < len; i++) {
			if (rres[i] != "\0") {
				printf("%3d", i + 1);
				cout << "." << rres[i] << endl;
			}
		}
		scanf("%d", &row);
	}
}