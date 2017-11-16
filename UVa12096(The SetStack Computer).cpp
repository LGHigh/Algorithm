#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x) {
	if (IDcache.count(x))return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}


int main() {
	stack<int> s;
	int num;
	cin >> num;
	while (num--) {
		int n;
		cin >> n;
		while (n--) {
			string Op;
			cin >> Op;
			if (Op == "PUSH")s.push(ID(Set()));
			else if (Op == "DUP")s.push(s.top());
			else {
				Set x1 = Setcache[s.top()]; s.pop();
				Set x2 = Setcache[s.top()]; s.pop();
				Set x;
				if (Op == "UNION")set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
				if (Op == "INTERSECT")set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
				if (Op == "ADD") { x = x2; x.insert(ID(x1)); }
				s.push(ID(x));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
}