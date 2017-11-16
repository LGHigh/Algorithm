#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, m;
	while (cin >> n >> k >> m && n) {
		vector<int>p;
		int left = n;
		p.resize(n+1);
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
		int a = n, b = 1;
		while (left) {
			for (int i = 0; i < k; i++) {
				do {
					a = (a + 1 + n + 1) % (n + 1);
				} while (!p[a]);
			}
			printf("%3d", p[a]); 
			for (int i = 0; i < m; i++) {
				do {
					b = (b - 1 + n + 1) % (n + 1);
				} while (!p[b]);
			}
			if (p[b] == p[a]) { p[a] = 0; left--; }
			else {
				printf("%3d", p[b]);
				p[a] = 0; p[b] = 0;
				left -= 2;
			}
			if (left)
				printf(",");
		}
		printf("\n");
	}
}

/*
int n,k,m,a[25];

int go(int p,int d,int t){
    do{
        p=(p+d+n-1)%n+1;
    }while(a[p]==0);
    return p;
}

int main(){
    while(scanf("%d%d%d",&d,&k,&m)==3 && n){
        for(int i=1;i<=n;i++)a[i]=i;
        int left=n;
        int p1=n,p2=1;
        while(left){
            p1=go(p1,1,k);
            p2=go(p2,-1,k);
            printf("%3d",p1)left--;
            if(p2!=p1){printf("%3d",p2);left--;}
            a[p1]=a[p2]=0;
            if(left)printf(",");
        }
        printf("\n");
    }
    return 0;
}
*/