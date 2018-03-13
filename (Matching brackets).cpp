#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string str1;

int main() {
	while (cin >> str1) {
		int len = str1.length();
		stack<int> tmp;
		stack<int> res;
		for (int i = 0; i < len; i++) {
			if (str1[i] == '(')tmp.push(i);
			else if (str1[i] == ')') {
				if (tmp.empty())res.push(i);
				else tmp.pop();
			}
		}
		string str2(len, ' ');
		while (!tmp.empty()) {
			str2[tmp.top()] = '$'; tmp.pop();
		}
		while (!res.empty()) {
			str2[res.top()] = '?'; res.pop();
		}
		cout << str1 << endl;
		cout << str2 << endl;
	}
	return 0;
}