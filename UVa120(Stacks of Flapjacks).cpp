#include <cstdio>
using namespace std;

int stk[32],nOfstk,Max,Max_pos;
void flip(int n);
//在code裡為求方便index是從左邊1,2,..,n到右邊，與題目的位置標示相反，在print的時候才換成題目的標示方法
int main()
{
    char line[200];
    while(gets(line)){
        nOfstk=0;
        for(int i=0;i<32;i++) stk[i]=0;
        for(int i=0;line[i];i++){
            if(line[i]==' '){
                printf("%d ",stk[nOfstk]);
                nOfstk++;
            }
            else{
                stk[nOfstk]*=10;
                stk[nOfstk]+=(line[i]-'0');
            }
        }
        printf("%d\n",stk[nOfstk]);

        //每次都將最大值放到右邊
        for(int i=nOfstk;i>=0;i--){
            Max=0;
            for(int j=0;j<=i;j++)  //找剩下未排序的最大值
                if(stk[j]>Max){ Max=stk[j]; Max_pos=j;}
            if(Max_pos!=i){        //最大值不在最右
                if(Max_pos!=0)     //不在最左
                    flip(Max_pos); //先翻到最左
                flip(i);           //再翻到最右
            }
        }
        printf("0\n");
    }
    return 0;
}
void flip(int n)
{
    printf("%d ",nOfstk-n+1);
    int temp[32];
    for(int i=0;i<=n;i++)
        temp[i]=stk[i];
    for(int i=0,j=n;i<=n;i++,j--){
        stk[i]=temp[j];
        if(stk[i]==Max) Max_pos=i;
    }
}