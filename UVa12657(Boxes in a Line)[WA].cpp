#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int>Left;
vector<int>Right;

void PutLeft(int n1,int n2) {
	Left[Right[n1]] = Left[n1];
	Right[Left[n1]] = Right[n1];
	Left[n1] = Left[n2];
	Right[n1] = n2;
	Right[Left[n1]] = n1;
	Left[Right[n1]] = n1;
}

void PutRight(int n1, int n2) {
	Left[Right[n1]] = Left[n1];
	Right[Left[n1]] = Right[n1];
	Right[n1] = Right[n2];
	Left[n1] = n2;
	Right[Left[n1]] = n1;
	Left[Right[n1]] = n1;
}

int main() {
	int ncmd;
	int nbox;
	int Kase = 0;
	while (cin >> nbox>>ncmd) {
		Left.clear(); Right.clear();
		Left.resize(nbox + 2);
		Right.resize(nbox + 2);
		for (int i = 1; i < nbox + 1; i++) {
			Left[i] = i - 1;
			Right[i] = i + 1;
		}
		Right[0] = 1;
		Left[nbox + 1] = nbox;
		int inv = 0;
		for (int i = 0; i < ncmd; i++) {
			int cmd; cin >> cmd;
			if (cmd == 4)inv = !inv;
			else {
				int n1, n2; cin >> n1 >> n2;
				if (cmd == 1) {
					if (!inv && Left[n2] != n1) PutLeft(n1, n2);
					else if (inv && Right[n2] != n1)PutRight(n1, n2);
				}
				else if (cmd == 2) {
					if (!inv && Right[n2] != n1) PutRight(n1, n2);
					else if (inv && Left[n2] != n1)PutLeft(n1, n2);
				}
				else {
					int left = Left[n1], right = Right[n1];
					Left[n1] = Left[n2]; Left[n2] = left;
					Right[n1] = Right[n2]; Right[n2] = right;
					Left[Right[n1]] = n1; Right[Left[n1]] = n1;
					Left[Right[n2]] = n2; Right[Left[n2]] = n2;
				}
			}
		}
		long long sum = 0, now;
		if (!inv) {
			now = 0;
			for (int i = 0; i < nbox; i++) {
				if (i % 2 == 0)
					sum += Right[now];
				now = Right[now];
				//cout << now << endl;
			}
		}
		else {
			now = nbox + 1;
			for (int i = 0; i < nbox; i++) {
				if (i % 2 == 0)
					sum += Left[now];
				now = Left[now];
				//cout << now << endl;
			}
		}
		cout << "Case " << ++Kase << ": " << sum << endl;
	}
	return 0;
}