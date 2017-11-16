#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int pow(int a, int b) {
	if (b == 0)return 1;
	int tmp = 1;
	for (int i = 0; i < b; i++) {
		tmp *= a;
	}
	return tmp;
}

int main() {
	string a;
	while (getline(cin, a)) {
		int leng = 0;
		int len = a.length(), j = 0;
		vector<char>ch[7];
		while (len) {
			leng++;
			int tmp = pow(2, leng) - 1;
			for (int i = 0; i < tmp; i++) {
				ch[leng - 1].push_back(a[j]);
				len--; j++;
				if (!len)break;
			}
		}
		len = 0;
		int tmp;
		for (int i = 0; i < 3; i++) {
			do {
				tmp = getchar();
			} while (tmp == '\n');
			if (tmp - '0')len += pow(2, 2 - i);
		}
		while (len != 0) {
			int cha = 0;
			for (int i = 0; i < len; i++) {
				do {
					tmp = getchar();
				} while (tmp == '\n');
				tmp = tmp - '0';
				if (tmp)cha += pow(2, len - 1 - i);
			}
			if (cha != pow(2, len) - 1)printf("%c", ch[len - 1][cha]);
			else {
				len = 0;
				for (int i = 0; i < 3; i++) {
					do {
						tmp = getchar();
					} while (tmp == '\n');
					if (tmp - '0')len += pow(2, 2 - i);
				}
			}
		}
		printf("\n");
		getline(cin, a);
	}
}

/*
int code[8][1<<8];


int readchar(){
    for(;;){
        int ch=getchar();
        if(ch!='\n' && ch!='\r')return ch;
    }
}

int readint(int c){
    int v=0;
    while(c--)v=v*2+readchar()-'0';
    return v;
}

int readcodes(){
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    for(int len=2;len<=7;len++){
        for(int i=0;i<(1<<len)-1;i++){
            int ch=getchar();
            if(ch==EOF)return 0;
            if(ch=='\n' || ch=='\r')return 1;
            code[len][i]=ch;
        }
    }
    return 1;
}

int main(){
    while(readcodes()){
        for(;;){
            int len=readint(3);
            if(len==0)break;
            for(;;){
                int v=readint(len);
                if(v==(1<<len)-1)break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}
*/