#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T, n, t;
int song[60], d[100][10000][2];

int main() {
	cin >> T;
	int kase = 0;
	while (kase++ < T) {
		memset(song, 0, sizeof(song));
		memset(d, 0, sizeof(d));
		cin >> n >> t;
		for (int i = 0; i < n; i++)
			cin >> song[i];
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j <= t; j++) {
				d[i][j][1] = (i == n - 1 ? 0 : d[i + 1][j][1]);
				d[i][j][0] = (i == n - 1 ? 0 : d[i + 1][j][0]);
				if (j > song[i]) {
					if (d[i][j][0] < (d[i + 1][j - song[i]][0] + 1)) {
						d[i][j][0] = d[i + 1][j - song[i]][0] + 1;
						d[i][j][1] = d[i + 1][j - song[i]][1] + song[i];
					}
					else if (d[i][j][0] == (d[i + 1][j - song[i]][0] + 1)) {
						d[i][j][1] = max(d[i][j][1], d[i + 1][j - song[i]][1] + song[i]);
					}
				}
			}
		cout << "Case " << kase << ": ";
		cout << d[0][t][0]+1 << " " << d[0][t][1] + 678 << endl;
	}
	return 0;
}