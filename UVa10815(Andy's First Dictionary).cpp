#include <string>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;
set<string> dict;

int main() {
	string s, buf;
	while (cin >> s) {
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (isalpha(s[i]))s[i] = tolower(s[i]);
			else s[i] = ' ';
		}
		stringstream ss(s);
		while (ss >> buf)dict.insert(buf);
	}
	for (set<string>::iterator i = dict.begin(); i != dict.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}