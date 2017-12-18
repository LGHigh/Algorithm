#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Range {
	int x1, x2;
	int num;
	int pos;
	Range(int x1, int x2, int num) :x1(x1), x2(x2), num(num), pos(0) {}
};

bool comp1(Range a, Range b) {
	return a.x1 < b.x1;
}

bool comp2(Range a, Range b) {
	return a.x2 < b.x2;
}

bool comp3(Range a, Range b) {
	return a.num < b.num;
}

int main() {
	int n;
	while (cin >> n && n) {
		int x1, y1, x2, y2;
		vector<Range>col, row;
		for (int i = 0; i < n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			col.push_back(Range(x1, x2, i)); row.push_back(Range(y1, y2, i));
		}
		stable_sort(col.begin(), col.end(), comp2); stable_sort(row.begin(), row.end(), comp2);
		int ok = 0;
		for (int i = 0; i < n; i++) {
			int okc = 0;
			for (int j = 0; j < n; j++) {
				if ( !col[j].pos && col[j].x1 <= i + 1 && col[j].x2>=i+1) { col[j].pos = i + 1; okc = 1; break; }
			}
			if (!okc) { ok = 1; break; }
			for (int j = 0; j < n; j++) {
				if ( !row[j].pos && row[j].x1 <= i + 1 && row[j].x2>=i+1) { row[j].pos = i + 1; okc = 0; break; }
			}
			if (okc) { ok = 1; break; }
		}

		if (ok)cout << "IMPOSSIBLE" << endl;
		else {
			sort(row.begin(), row.end(), comp3);
			sort(col.begin(), col.end(), comp3);
			for (int i = 0; i < n; i++) {
				cout << col[i].pos << " " << row[i].pos << endl;
			}
		}
	}
	return 0;
}