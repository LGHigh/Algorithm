#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define maxn 5010

using namespace std;
char a[maxn],b[maxn];
int d[maxn][maxn],c[maxn][maxn];
int sa[26],ea[26],sb[26],eb[26];



int main()
{
    //freopen("H:\\c++\\file\\stdin.txt","r",stdin);
    int T;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%s%s",a+1,b+1);
        int la = strlen(a+1);
        int lb = strlen(b+1);
        for(int i=1 ; i<=la ; ++i)a[i]-='A';
        for(int i=1 ; i<=lb ; ++i) b[i] -='A';
        for(int i=0 ; i<26 ; ++i){
            sa[i] = sb[i] = INF;
            ea[i] = eb[i] = -INF;
        }

        for(int i=1 ; i<=lb ; ++i){
            sb[b[i]] = min(sb[b[i]],i);
            eb[b[i]] = i;
        }
        for(int i=1 ; i<=la; ++i){
            sa[a[i]] = min(sa[a[i]],i);
            ea[a[i]] = i;
        }



        d[0][0] =c[0][0] = 0;
        for(int i=0 ; i<=la ; i++)
        {
            for(int j=0 ; j<=lb ; ++j)
            {

                if(!i && !j)continue;
                //d
                int v1 = INF;int v2 = INF;
                if(i)  v1 = d[i-1][j] + c[i-1][j];
                if(j)  v2 = d[i][j-1] + c[i][j-1] ;
                d[i][j] = min(v1,v2);


                //c
                if(i)
                {
                    c[i][j] = c[i-1][j];
                    if(sa[a[i]] == i && sb[a[i]] >j)c[i][j]++ ;
                    if(ea[a[i]] == i &&eb[a[i]]<=j) c[i][j] --;
                }else if(j)
                {
                    c[i][j] = c[i][j-1];
                    if(sb[b[j]] == j &&sa[b[j]]>i)c[i][j] ++;
                    if(eb[b[j]] == j&&ea[b[j]] <=i)c[i][j]--;
                }

            }

        }
        printf("%d\n",d[la][lb]);
     } 

    return 0;
}
