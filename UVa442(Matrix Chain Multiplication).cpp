#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
using namespace std;


struct Matrix {
	int col;
	int row;
	Matrix(int row, int col) :col(col), row(row) {}
	Matrix() {}
};

int main() {
	int n; cin >> n;
	vector<Matrix>name;

	name.resize(30);
	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		cin >> name[(int)(ch - 'A')].row >> name[(int)(ch - 'A')].col;
	}
	string cmd;
	while (cin >> cmd) {
		int times = 0; bool error = false;
		int len = cmd.length();
		stack<Matrix>tmp;
		for (int i = 0; i < len; i++) {
			if (isalpha(cmd[i]))tmp.push(Matrix(name[(int)(cmd[i] - 'A')].row, name[(int)(cmd[i] - 'A')].col));
			else if (cmd[i] == ')') {
				Matrix m1 = tmp.top(); tmp.pop();
				Matrix m2 = tmp.top(); tmp.pop();
				if (m1.row != m2.col) { error = true; break; }
				times += m1.row*m1.col*m2.row;
				tmp.push(Matrix(m2.row, m1.col));
			}
		}
		if (error)cout << "error" << endl;
		else cout << times << endl;
	}
}