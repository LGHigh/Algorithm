#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node {
	string str;
	int num;
	node(string str, int num) :str(str), num(num) {}
	bool operator > (node& tmp) { return num < tmp.num; }
	bool operator < (node& tmp) { return num > tmp.num; }
};

int main() {
	string in;
	
	while (cin >> in) {
		int len = in.length();
		string res;
		vector<node>q;

		string tmp; tmp.clear();
		int first = 0, last = 1;
		char lasttoken = ']';
		for (int i = 0; i < len; i++) {
			if (in[i] != '[' && in[i] != ']')tmp += in[i];
			else if (in[i] == '[' ) {
				if (!tmp.empty()) {
					if (lasttoken == ']') {
						q.push_back(node(tmp, last));
						last++; tmp.clear();
					}
					else {
						q.push_back(node(tmp, first));
						first--; tmp.clear();
					}
				}
				lasttoken = ']';
			}
			else if (in[i] == ']' ) {
				if (!tmp.empty()) {
					if (lasttoken == ']') {
						q.push_back(node(tmp, last));
						last++; tmp.clear();
					}
					else {
						q.push_back(node(tmp, first));
						first--; tmp.clear();
					}
				}
				lasttoken = '[';
			}
		}
		if (!tmp.empty()) {
			if (lasttoken == ']')q.push_back(node(tmp, last));
			else q.push_back(node(tmp, first));
		}
		sort(q.begin(), q.end());
		int l = q.size();
		for (int i = 0; i < l; i++) {
			cout << q[i].str;
		}
		cout << endl;
	}
	return 0;
}

/*
const int maxn=100000+5;
int last,cur,next[maxn];
char s[maxn];

int main(){
    while(scanf("%s",s+1)==1){
        int n=strlen(s+1);
        last=cur=0;
        next[0]=0;

        for(int i=1;i<=n;i++){
            char ch=s[i];
            if(ch=='[')cur=0;
            else if(ch==']')cur=last;
            else{
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last)last=i;
                cur=i;
            }
        }
        for(int i=next[0];i!=0;i=next[i])
            printf("%c",s[i]);
        printf("\n");
    }
}
*/