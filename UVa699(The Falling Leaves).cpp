/*
在处理输出时要注意，留心是<<endl<<endl，还是在开头输出<<endl
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int Min=0;
map<int, int>sum;
struct node {
	int pos;
	int weight;
	node* Left;
	node* Right;
	node() { pos = 0; weight = 0; Left = NULL; Right = NULL; }
};

void read(node* tree, int pos, int weight) {
	tree->weight = weight;
	tree->pos = pos;
	Min = Min > pos ? pos : Min;
	int left; cin >> left;
	if (left != -1){
		tree->Left = new node;
		read(tree->Left, pos - 1,left);
	}
	int right; cin >> right;
	if (right != -1) {
		tree->Right = new node;
		read(tree->Right, pos + 1,right);
	}
}

void solve(node* tree) {
	if (!sum.count(tree->pos))sum[tree->pos] = tree->weight;
	else sum[tree->pos] += tree->weight;
	if (tree->Left)solve(tree->Left);
	if (tree->Right)solve(tree->Right);
}

int main() {
	int kase = 0;
	int tmp; cin >> tmp;
	while (tmp != -1) {
		node* tree = new node;
		read(tree, 0, tmp);
		solve(tree);
		int len = sum.size();
		//if (kase)cout << endl;
		cout << "Case " << ++kase << ":" << endl;
		for (int i = 0; i < len - 1; i++) {
			cout << sum[i + Min] << " ";
		}
		cout << sum[len - 1 + Min] << endl << endl;
		cin >> tmp; Min = 0; sum.clear();
	}
	return 0;
}