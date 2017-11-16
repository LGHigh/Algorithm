#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test;
	string ques, ans;
	while (cin >> test && test != -1) {
		int chance = 7, cho = 0;
		cin >> ques >> ans;
		int qlen = ques.length();
		int alen = ans.length();
		for (int i = 0; i < alen; i++) {
			int ok = 0;
			for (int j = 0; j < qlen; j++) {
				if (ans[i] == ques[j]) {
					ques[j] = ' ';
					ok = 1;
				}
			}
			if (!ok)chance--;
		}
		for (int i = 0; i < qlen; i++)
			if (ques[i] != ' ')cho = 1;
		printf("Round %d\n", test);
		if (chance <= 0)printf("You lose.\n");
		else if (cho == 1)printf("You chickened out.\n");
		else printf("You win.\n");
	}
}

/*

int left,chance;
char s[100],s2[100];
int win,lose;

void guess(char ch){
    int bad=1;
    for(int i=0;i<strlen(s);i++)
        if(s[i] == ch){
            left--;s[i]=' ';bad=0;
        }
        if(bad)--chance;
        if(!chance)lose=1;
        if(!left)win=1;
}

int main(){
    int rnd;
    while(scanf("%d%s%s",&rnd,s,s2)==3 && rnd != -1){
        printf("Round %d\n",rnd);
        win=lose=0;
        left=strlen(s);
        chance=7;
        for(int i=0;i<strlen(s2);i++){
            guess(s2[i]);
            if(win||lose)break;
        }
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}

*/