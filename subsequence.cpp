#include <stdio.h>

int main() {
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	long long begin, end;
	int cnt = 0;
	while (fscanf(fin, "%lld %lld", &begin, &end) == 2 && begin && end) {
		double sum = 0;
		for (long long i = begin; i <= end; i++) {
			sum = sum + (double)(1.0 / (i*i));
		}
		fprintf(fout, "Case %d:%.5f\n", ++cnt, sum);
	}
	return 0;
}