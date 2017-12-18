#include <iostream>
using namespace std;

char a[52];

int main() {
	int n;
	for (int i = 0; i < 26; i++)a[i] = (char)('A' + i);
	for (int i = 26; i < 52; i++)a[i] = (char)('a' + i - 26);
	while (cin >> n) {
		cout << "2 " << n << " " << n << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)cout << a[i];
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << a[j];
			cout << endl;
		}
		cout << endl;
	}