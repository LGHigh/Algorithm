#include <iostream>  
#include <cstdio>  
#include <string>  
#include <vector>
#include <cstring>  
using namespace std;

int main() {
	int row, col, test=0;
	cin >> row >> col;
	while (row && col) {
		if (test != 0)printf("\n");
		int n; cin >> n;
		int cnt = n;
		vector<string> cmd;
		vector<vector<int>> x;
		while (cnt--) {
			string tmp; vector<int> tx;
			cin >> tmp;
			cmd.push_back(tmp);
			if (tmp != "EX") {
				int t, tt; cin >> t;
				tx.push_back(t);
				for (int i = 0; i < t; i++) {
					cin >> tt; tx.push_back(tt);
				}
				x.push_back(tx);
			}
			else {
				vector<int>tx;
				int t;
				for (int i = 0; i < 4; i++) {
					cin >> t; tx.push_back(t);
				}
				x.push_back(tx);
			}
		}
		printf("Spreadsheet #%d\n", ++test);
		cin >> cnt;
		while (cnt--) {
			int tx, ty; cin >> tx >> ty;
			printf("Cell data in (%d,%d) ", tx, ty);
			int ok = 0;
			for (int i = 0; i < n; i++) {
				if (cmd[i] == "EX") {
					if (x[i][0] == tx && x[i][1] == ty) {
						tx = x[i][2]; ty = x[i][3];
					}
					else if (x[i][2] == tx && x[i][3] == ty) {
						tx = x[i][0]; ty = x[i][1];
					}
				}
				else if (cmd[i] == "DR") {
					int sum = 0;
					for (int j = 0; j < x[i][0]; j++) {
						if (x[i][j + 1] < tx)sum++;
						else if (x[i][j + 1] == tx) { ok = 1; break; }
					}
					tx -= sum;
				}
				else if (cmd[i] == "DC") {
					int sum = 0;
					for (int j = 0; j < x[i][0]; j++) {
						if (x[i][j + 1] < ty)sum++;
						else if (x[i][j + 1] == ty) { ok = 1; break; }
					}
					ty -= sum;
				}
				else if (cmd[i] == "IC") {
					int sum = 0;
					for (int j = 0; j < x[i][0]; j++) {
						if (x[i][j + 1] <= ty)sum++;
					}
					ty += sum;
				}
				else if (cmd[i] == "IR") {
					int sum = 0;
					for (int j = 0; j < x[i][0]; j++) {
						if (x[i][j + 1] <= tx)sum++;
					}
					tx += sum;
				}
			}
			if (ok)printf("GONE\n");
			else printf("moved to (%d,%d)\n", tx, ty);
		}
		cin >> row >> col;
	}
}

/*
#define maxd 100
#define BIG 1000
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd][maxd],cols[maxd];

void copy(char type,int p,int q){
    if(type=='R'){
        for(int i=1;i<=c;i++)
            d[p][i]=d2[q][i];
    }
    else{
        for(int i=1;i<=r;i++){
            d[i][p]=d2[i][q];
        }
    }
}

void del(char type){
    memcpy(d2,d,sizeof(d));
    int cnt=type=='R'?r:c,cnt2=0;
    for(int i=1;i<=cnt;i++){
        if(!cols[i])copy(type,++cnt2,i);
    }
    if(type=='R')r=cnt2;
    else c=cnt2;
}

void ins(char type){
    memcpy(d2,d,sizeof(d));
    int cnt=type=='R'?r:c,cnt2=0;
    for(int i=1;i<=cnt;i++){
        if(cols[i])copy(type,++cnt2,0);
        copy(type,++cnt2,i);
    }
    if(type=='R')r=cnt2;
    else c=cnt2;
}

int main(){
    int r1,c1,r2,c2,q,kase=0;
    char cmd[10];
    memset(d,0,sizeof(d));
    while(scanf("%d%d%d",&r,&c,&n)==3 && r){
        int r0=r,c0=c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                d[i][j]=i*BIG+j;
        while(n--){
            scanf("%s",cmd);
            if(cmd[0]=='E'){
                scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
                int t=d[r1][c1];d[r1][c1]=d[r2][c2];d[r2][c2]=t;
            }
            else {
                int a,x;
                scanf("%d",&a);
                memset(cols,0,sizeof(cols));
                for(int i=0;i<a;o++){scanf("%d",&x);cols[x]=1;}
                if(cmd[0]=='D')del(cmd[1]);else ins(cmd[1]);
            }
        }
        memset(ans,o,sizeof(ans));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                ans[d[i][j]/BIG][d[i][j]%BIG]=i*BIG+j;
        if(kase>0)printf("\n");
        printf("Spreadsheet #%d\n",++kase);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&r1,&c1);
            printf("Cell data in (%d,%d) ",r1,c1);
            if(ans[r1][c1]==0)printf("GONE\n");
            else printf("moved to (%d,%d)\n",ans[r1][c1]/BIG,ans[r1][c1]%BIG);
        }
    }
    return 0;
}
*/