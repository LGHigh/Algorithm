#include <stdio.h>

int main() {
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	int a, b, c;
	int cnt = 0;
	while (fscanf(fin, "%d %d %d", &a, &b, &c) == 3 && a && b && c) {
		fprintf(fout, "Case %d:%.*lf\n", ++cnt, c, 1.0*a / b);
	}
	return 0;
}