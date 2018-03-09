#include <iostream>
#include <algorithm>
using namespace std;

struct Bulb {
	int V, K, C, L;
};

bool operator <(Bulb a, Bulb b) {
	return  a.V < b.V;
}

int main() {
	int n;
	while (cin >> n && n) {
		Bulb a[1010];
		for (int i = 0; i < n; i++)
			cin >> a[i].V >> a[i].K >> a[i].C >> a[i].L;
		sort(a, a + n);
		int s[1010]; s[0] = a[0].L;
		for (int i = 1; i < n; i++) {
			s[i] = s[i - 1] + a[i].L;
		}
		int d[1010]; d[0] = a[0].K + a[0].C * a[0].L;
		for (int i = 1; i < n; i++) {
			d[i] = d[i - 1] + a[i].K + a[i].C * a[i].L;
			for (int j=i-1; j >= -1; j--) {
				if (j >= 0)
					d[i] = min(d[i], d[j] + (s[i] - s[j])*a[i].C + a[i].K);
				else
					d[i] = min(d[i], s[i] * a[i].C + a[i].K);
			}
		}
		cout << d[n - 1] << endl;
	}
	return 0;
}