#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int coeff[3] = { 2,3,5 };

int main() {
	set<LL>s;
	set<LL>::iterator st;
	s.insert(1);
	st = s.begin();
	for (int i = 0; i < 1500; i++) {
		s.insert(*st * 2);
		s.insert(*st * 3);
		s.insert(*st * 5);
		st++;
	}
	cout << "The 1500'th ugly number is " << *(--st) << ".\n";
	return 0;
}