#include <bits/stdc++.h>  
using namespace std;  
  
struct Node{  
    double l, r;  
    Node(double l, double r):l(l), r(r) {}  
};  
const int MAXN = (1<<6);  
vector<Node> nodes[MAXN];  
double r, w[6], sumw[MAXN];  
int n, s;  
bool vis[MAXN];  
  
inline int bit_cnt(int x)  
{  
    return x == 0 ? 0 : bit_cnt(x / 2) + (x & 1);  
}  
  
void DFS(int n)  
{  
    if(vis[n]) return;  
    vis[n] = true;  
    if(bit_cnt(n)==1){  
        nodes[n].push_back(Node(0, 0));  
        return ;  
    }  
    for(int l = (n-1)&n; l > 0; l = (l-1)&n){  
        int r = n^l;  
        DFS(l), DFS(r);  
        for(size_t i = 0; i < nodes[l].size(); i++)  
            for(size_t j = 0; j < nodes[r].size(); j++){  
                double ll = min(-sumw[r]/(sumw[l]+sumw[r]) + nodes[l][i].l, nodes[r][j].l + sumw[l]/(sumw[l]+sumw[r]));  
                double rr = max(sumw[l]/(sumw[l]+sumw[r]) + nodes[r][j].r, nodes[l][i].r - sumw[r]/(sumw[l]+sumw[r]));  
                nodes[n].push_back(Node(ll, rr));  
            }  
    }  
}  
  
int main()  
{  
    ios::sync_with_stdio(false);  
    int T; cin >> T;  
    while(memset(sumw, 0, sizeof(sumw)), memset(vis, false, sizeof(vis)), T--){  
        for(int i = 0; i < MAXN; i++)  
            nodes[i].clear();  
        cin >> r >> s;  
        const int maxs = (1<<s)-1;  
        for(int i = 0; i < s; i++)  
            cin >> w[i];  
        for(int i = 0; i <= maxs; i++)  
            for(int j = 0; j < s; j++)  
                if(i & (1<<j))  
                    sumw[i] += w[j];  
        DFS(maxs);  
        double ans = -1.0;  
        for(size_t i = 0; i < nodes[maxs].size(); i++)  
            if(nodes[maxs][i].r - nodes[maxs][i].l < r)  
                ans = max(ans, nodes[maxs][i].r - nodes[maxs][i].l);  
        if(ans == -1) puts("-1");  
        else printf("%.10f\n", ans);  
    }  
    return 0;  
}  