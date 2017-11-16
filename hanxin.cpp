#include <stdio.h>

int main() {
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	int a, b, c, cnt = 0;
	while(fscanf_s(fin,"%d %d %d",&a,&b,&c)==3){
		int ok = 0;
		for (int i = 10; i < 101; i++) {
			if (i % 3 == a && i % 5 == b && i % 7 == c) {
				fprintf(fout, "Case %d:%d\n", ++cnt, i);
				ok = 1;
				break;
			}
		}
		if (!ok)fprintf(fout, "Case %d:No answer\n", ++cnt);
	}
	return 0;
}