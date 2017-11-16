/*
巧用continue让循环进行
*/

#include <iostream>
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



int main() {
	string tmp;
	node* root = new node;
	int ok = 0;
	while (cin >> tmp) {
		if (tmp != "()") {
			int com = tmp.find(',');
			string ns = tmp.substr(1, com - 1);
			string pos = tmp.substr(com + 1, tmp.length() - com - 2);
			int len = pos.length();
			if (len) {
				node* now = root;
				for (int i = 0; i < len; i++) {
					if (pos[i] == 'L') {
						if (!now->Left) { now->Left = new node; now->Left->num = -1; }
						now = now->Left;
					}
					else {
						if (!now->Right) { now->Right = new node; now->Right->num = -1; }
						now = now->Right;
					}
				}
				if (now->num > 0)ok = 1;
				now->num = stoi(ns);
			}
			else root->num = stoi(ns);
			continue;
		}

		queue<node*>Tree;
		vector<int>q;
		bool error = false;
		if (root->num > 0) {
			//cout << root->num;
			Tree.push(root);
			while (!Tree.empty()) {
				if (Tree.front()->Left) {
					if (Tree.front()->Left->num > 0)
						Tree.push(Tree.front()->Left);
					else { error = true; break; }
				}
				if (Tree.front()->Right) {
					if (Tree.front()->Right->num > 0)
						Tree.push(Tree.front()->Right);
					else { error = true; break; }
				}
				q.push_back(Tree.front()->num);
                //delete Tree.front();
                

				Tree.pop();
			}
		}
		else error = true;
		if (error || ok)cout << "not complete" << endl;
		else {
			int len = q.size();
			for (int i = 0; i < len - 1; i++)cout << q[i] << " ";
			cout << q[len - 1] << endl;
		}
		root->Left = NULL; root->Right = NULL; root->num = 0; ok = 0;
	}
	return 0;
}