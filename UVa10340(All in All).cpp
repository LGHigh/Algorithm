#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str, substr;
	while (cin >> substr) {
		cin >> str;
		int ok = 0;
		int j = 0, sublen = substr.length();
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] == substr[j])j++;
			if (j == sublen) {
				ok = 1;
				break;
			}
		}
		if (ok)printf("Yes\n");
		else printf("No\n");
	}
}