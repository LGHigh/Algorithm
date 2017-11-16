#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int pos = 0, sum = 0;
struct node {
	int col;
	node* n1;
	node* n2;
	node* n3;
	node* n4;
	node() { col = -1; n1 = n2 = n3 = n4 = NULL; }
};

void read(string cmd,node* tree) {

	tree->n1 = new node;
	if (cmd[pos] == 'p') {  pos++; read(cmd, tree->n1); }
	else {
		if (cmd[pos] == 'e') tree->n1->col = 0;
		else tree->n1->col = 1;
		pos++;
	}
	tree->n2 = new node;
	if (cmd[pos] == 'p') { pos++; read(cmd, tree->n2); }
	else {
		if (cmd[pos] == 'e') tree->n2->col = 0;
		else tree->n2->col = 1;
		pos++;
	}
	tree->n3 = new node;
	if (cmd[pos] == 'p') { pos++; read(cmd, tree->n3); }
	else {
		if (cmd[pos] == 'e') tree->n3->col = 0;
		else tree->n3->col = 1;
		pos++;
	}
	tree->n4 = new node;
	if (cmd[pos] == 'p') { pos++; read(cmd, tree->n4); }
	else {
		if (cmd[pos] == 'e') tree->n4->col = 0;
		else tree->n4->col = 1;
		pos++;
	}
}

void plu(node* tree1, node* tree2, node* tree) {
	if (tree1->col == 1 || tree2->col == 1)tree->col = 1;
	else if (tree1->col == 0 && tree2->col == 0)tree->col = 0;
	else {
		if (tree1->col == 0) { tree->col = tree2->col; tree->n1 = tree2->n1; tree->n2 = tree2->n2; tree->n3 = tree2->n3; tree->n4 = tree2->n4; }
		else if (tree2->col == 0) { tree->col = tree1->col; tree->n1 = tree1->n1; tree->n2 = tree1->n2; tree->n3 = tree1->n3; tree->n4 = tree1->n4; }
		else {
			tree->n1 = new node; tree->n2 = new node; tree->n3 = new node; tree->n4 = new node;
			plu(tree1->n1, tree2->n1, tree->n1);
			plu(tree1->n2, tree2->n2, tree->n2);
			plu(tree1->n3, tree2->n3, tree->n3);
			plu(tree1->n4, tree2->n4, tree->n4);
		}
	}
}

void solve(node* tree,int n) {
	if (tree->col == 1) { sum += (n*n); return; }
	else {
		if (tree->col == 0)return;
		solve(tree->n1, n / 2);
		solve(tree->n2, n / 2);
		solve(tree->n3, n / 2);
		solve(tree->n4, n / 2);
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string cmd;
		node* tree1 = new node;
		node* tree2 = new node;
		cin >> cmd;
		if (cmd[pos] == 'p') { pos++; read(cmd,tree1); }
		else {
			if (cmd[pos] == 'e') { tree1->col = 0; }
			else tree1->col = 1;
		}
		pos = 0;
		cin >> cmd;
		if (cmd[pos] == 'p') { pos++; read(cmd, tree2); }
		else {
			if (cmd[pos] == 'e') { tree2->col = 0; }
			else tree2->col = 1;
		}
		node* tree = new node;
		plu(tree1, tree2, tree);
		solve(tree, 32);
		cout <<"There are "<< sum <<" black pixels."<< endl;
		pos = 0; sum = 0;
	}
	return 0;
}

/*
const int len=32;
const int maxn=1024+10;
char s[maxn];
int buf[len][len],cnt;

void draw(const char* s, int& p,int r,int c,int w){
    char ch=s[p++];
    if(ch=='p'){
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }
    else if(ch=='f'){
        for(int i=r;i<c+w;i++){
            for(int j=c;j<c+w;j++){
                if(buf[i][j]==0){buf[i][j]=1;cnt++;}
            }
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(buf,0,sizeof(buf));
        cnt=0;
        for(int i=0;i<2;i++){
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}
*/