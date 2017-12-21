#include <iostream>
#include <set>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

struct node {
	int x, y;
	node(int x, int y) :x(x), y(y) {}
};

bool operator < (const node &a,const node &b) {
	if (a.x < b.x)return true;
	if (a.x == b.x && a.y < b.y)return true;
	return false;
}

double dp[1100][1100];
vector<node>point;
int n;

double dist(node& a, node& b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double d(int x, int y) {
	double& ans = dp[x][y];
	if (ans > 0)return ans;
	if (x == n - 1)return dist(point[y], point[n - 1]);
	if (y == n - 1)return dist(point[x], point[n - 1]);
	ans = min(d(max(x, y) + 1,y) + dist(point[x], point[max(x, y) + 1]), d(x,max(x, y) + 1) + dist(point[y], point[max(x, y) + 1]));
	return ans;
}

int main() {
	
	while (cin >> n) {
		point.clear();
		set<node>tmp;
		memset(dp, 0, sizeof(dp));
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			tmp.insert(node(x, y));
		}
		set<node>::iterator it = tmp.begin();
		while (it != tmp.end()) {
			point.push_back(node(it->x, it->y));
			it++;
		}
		d(0, 0);
		printf("%.2lf\n", dp[0][0]);
	}
 	return 0;
}