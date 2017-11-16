#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
bool error = false;
struct node {
	int weight;
	int len;
	node* Left;
	node* Right;
	node() { weight = 0; len = 0; Left = NULL; Right = NULL; }
};

void makeTree(int wl, int dl, int wr, int dr, node* tree) {
	if (wl == 0) {
		tree->Left = new node;
		tree->Left->len = dl;
		int lwl, ldl, lwr, ldr; cin >> lwl >> ldl >> lwr >> ldr;
		makeTree(lwl, ldl, lwr, ldr, tree->Left);
	}
	else {
		tree->Left = new node;
		tree->Left->len = dl;
		tree->Left->weight = wl;
	}
	if (wr == 0) {
		tree->Right = new node;
		tree->Right->len = dr;
		int rwl, rdl, rwr, rdr; cin >> rwl >> rdl >> rwr >> rdr;
		makeTree(rwl, rdl, rwr, rdr, tree->Right);
	}
	else {
		tree->Right = new node;
		tree->Right->len = dr;
		tree->Right->weight = wr;
	}
}

int makeSure(node* tree) {
	if (!tree->Left->weight)tree->Left->weight = makeSure(tree->Left);
	if (!tree->Right->weight)tree->Right->weight = makeSure(tree->Right);
	if (tree->Left->weight*tree->Left->len != tree->Right->weight*tree->Right->len) { error = true; return 0; }
	else return tree->Left->weight + tree->Right->weight;
}

int main() {
	int kase; cin >> kase;
	int i = 0;
	while (i<kase) {
		node* tree = new node;
		int wl, dl, wr, dr;
		cin >> wl >> dl >> wr >> dr;
		makeTree(wl, dl, wr, dr, tree);
		makeSure(tree);
		if (i++)cout << endl;
		if (error)cout << "NO" << endl;
		else cout << "YES" << endl;
		error = false;
	}
	return 0;
}

/*
#include <iostream>
using namespace std;

bool solve(int& w){
	int w1,d1,w2,d2;
	bool b1=true,b2=true;
	cin>>w1>>d1>>w2>>d2;
	if(!w1)b1=solve(b1);
	if(!w2)b2=solve(b2);
	w=w1+w2;
	return b1 && b2 && (w1*d1 == w2*d2);
}

int main(){
	int T,W;
	cin>>T;
	while(T--){
		if(solve(W))cout<<"YES\n";else cout<<"NO\n";
		if(T)cout<<"\n";
	}
	return 0;
}
*/