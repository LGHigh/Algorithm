#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct triangle {
	int x;
	int y;
};

bool operator > (triangle a, triangle b) {
	if (a.x > b.x)return true;
	else if (a.x == b.x && a.y > b.y)return true;
	return false;
}

int main() {
	int x, y;
	while (cin >> x) {
		cin >> y;
		triangle tri[6];
		tri[0].x = x > y ? x : y;
		tri[0].y = x > y ? y : x;
		for (int i = 1; i < 6; i++) {
			cin >> x >> y;
			tri[i].x = x > y ? x : y;
			tri[i].y = x > y ? y : x;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (!(tri[j] > tri[j + 1])) {
					int tmp;
					tmp = tri[j].x; tri[j].x = tri[j + 1].x; tri[j + 1].x = tmp;
					tmp = tri[j].y; tri[j].y = tri[j + 1].y; tri[j + 1].y = tmp;
				}
			}
		}
		int ok = 0;
		for (int i = 0; i < 3; i++) {
			if (!(tri[i].x == tri[i + 1].x))ok = 1;
			if (!(tri[i + 2].y == tri[i + 3].y))ok = 1;
		}
		if (!(tri[4].x == tri[5].x && tri[5].x == tri[0].y && tri[0].y == tri[1].y))ok = 1;
		if (ok)printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");
	}
}