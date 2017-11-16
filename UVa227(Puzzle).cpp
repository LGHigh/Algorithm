#include <stdio.h>
#include <string>
#include <cstring>

int main() {
	int cnt = 0;
	char t = getchar();
	while (t != 'Z') {
		char a[5][5];
		int col = 0, x, y;
		for (int row = 0; row < 5;) {
			if (t != '\n' && t != 32) {
				a[row][col] = t;
				col++;
			}
			else if (t == '\n' && col != 5) {
				a[row][4] = 32;
				x = row; y = 4;
				row++; col = 0;
			}
			else if ((int)t == 32) {
				a[row][col] = t;
				x = row; y = col;
				col++;
			}
			else {
				col = 0;
				row++;
			}
			t = getchar();
		}
		int ok = 0, br = 0;
		while (t!='0') {
			char tmp;
			switch (t) {
			case 'L':
				if (y == 0) { ok = 1; break; }
				tmp = a[x][y];
				a[x][y] = a[x][y - 1];
				a[x][y - 1] = tmp;
				y = y - 1;
				break;
			case 'B':
				if (x == 4) { ok = 1; break; }
				tmp = a[x][y];
				a[x][y] = a[x + 1][y];
				a[x + 1][y] = tmp;
				x = x + 1;
				break;
			case 'R':
				if (y == 4) { ok = 1; break; }
				tmp = a[x][y];
				a[x][y] = a[x][y + 1];
				a[x][y + 1] = tmp;
				y = y + 1;
				break;
			case 'A':
				if (x == 0) { ok = 1; break; }
				tmp = a[x][y];
				a[x][y] = a[x - 1][y];
				a[x - 1][y] = tmp;
				x = x - 1;
				break;
			case '0':
				br = 1;
				break;
			default:
				break;
			}
			t = getchar();
			if (br)break;
		}
		if (cnt != 0)printf("\n");
		printf("Puzzle #%d:\n", ++cnt);
		if (ok)printf("This puzzle has no final configuration.\n");
		else
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4; j++) {
					putchar(a[i][j]);
					putchar(' ');
				}
				putchar(a[i][4]);
				putchar('\n');
			}
		t = getchar();
		t = getchar();
	}
}