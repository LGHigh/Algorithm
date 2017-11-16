#include <iostream>
#include <string>
#include <set>
#include <string.h>
using namespace std;
int a[26][26], b[26], c[26];

bool toposort(int begin) {
	for (int i = 0; i < 26; i++) {
		if (a[begin][i]) {
			a[begin][i]--; b[begin]--; b[i]--;
			if (!toposort(i)) {
				a[begin][i]++; b[begin]++; b[i]++;
			}
			else return true;
		}
	}
	int sum = 0;
	for (int i = 0; i < 26; i++)sum += b[i];
	if (sum)return false;
	return true;
}

int main() {
	int cnt; cin >> cnt;
	while (cnt--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int num; cin >> num;
		string tmp;
		for (int i = 0; i < num; i++) {
			cin >> tmp;
			a[tmp[0] - 'a'][tmp[tmp.length() - 1] - 'a']++;
			b[tmp[0] - 'a']++; b[tmp[tmp.length() - 1] - 'a']++;
			c[tmp[0] - 'a']++; c[tmp[tmp.length() - 1] - 'a']--;
		}
		int n = 0; char begin = 0, end;
		for (int i = 0; i < 26; i++) {
			if (b[i] % 2) {
				if (begin) {
					end = i + 'a'; n++;
				}
				else { begin = i + 'a'; n++; }
			}
			
		}
		if (n > 2 || n == 1)cout << "The door cannot be opened." << endl;
		else if (n == 2) {
			if (c[begin - 'a'] > 0) {
				if (!toposort(begin - 'a'))cout << "The door cannot be opened." << endl;
				else cout << "Ordering is possible." << endl;
			}
			else {
				if (!toposort(end - 'a'))cout << "The door cannot be opened." << endl;
				else cout << "Ordering is possible." << endl;
			}
		}
		else {
			int ok = 0;
			for (int i = 0; i < 26; i++)if (b[i]) if(toposort(i)){
				cout << "Ordering is possible." << endl;
				ok = 1;
				break;
			}
			if(!ok) cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}