/*
leaf的更新要分两种情况讨论
*/

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int num;
	node* Left;
	node* Right;
	node() { num = 0; Left = NULL; Right = NULL; }
};

int Min=1000000000; int leaf=10000000;

void findMin(node* tree) {
	if (!tree->Left->num && !tree->Right->num) { Min = tree->num; leaf = tree->num; return; }
	if(tree->Left->num)
		if (tree->Left->Left->num || tree->Left->Right->num) { tree->Left->num += tree->num; findMin(tree->Left); }
		else {
			if (Min > (tree->num + tree->Left->num)) {
				Min = tree->num + tree->Left->num;
				leaf = tree->Left->num;
			}
			else if (Min == (tree->num + tree->Left->num))
				leaf = leaf < tree->Left->num ? leaf : tree->Left->num;
		}
	if(tree->Right->num)
		if (tree->Right->Left->num || tree->Right->Right->num) { tree->Right->num += tree->num; findMin(tree->Right); }
		else {
			if (Min > (tree->num + tree->Right->num)) {
				Min = tree->num + tree->Right->num;
				leaf = tree->Right->num;
			}
			else if(Min== (tree->num + tree->Right->num))
				leaf = leaf < tree->Right->num ? leaf : tree->Right->num;
		}
}

void makeTree(int inbegin, int inend,int postbegin,int postend, vector<int>in, vector<int>post, node* now) {
	if (inbegin == inend)return;
	now->Left = new node; now->Right = new node;
	int root = post[postend - 1];
	now->num = root;
	int i;
	for (i = inbegin; i < inend; i++) {
		if (in[i] == root)break;
	}
	makeTree(inbegin, i, postbegin, postbegin + i - inbegin, in, post, now->Left);
	makeTree(i + 1, inend, postend + i - inend, postend - 1, in, post, now->Right);
}

void deleteTree(node* tree) {
	if (!tree->num) { delete tree; }
	else {
		node* left = tree->Left; node* right = tree->Right;
		delete tree; deleteTree(left); deleteTree(right);
	}
}

int main() {
	string tmpin, tmppost;
	while (getline(cin, tmpin)) {
		getline(cin, tmppost);
		node* tree = new node;
		vector<int>in;
		vector<int>post;
		int x, y;
		stringstream sin(tmpin), spost(tmppost);
		while (sin >> x && spost >> y) { in.push_back(x); post.push_back(y); }
		makeTree(0, in.size(), 0, post.size(), in, post, tree);
		findMin(tree);
		cout << leaf << endl;
		deleteTree(tree);
		Min = 1000000000; leaf = 10000000;
	}
	return 0;
}