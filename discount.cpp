#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int tot = n * 95;
	if (tot >= 300)printf("%f", tot*0.85);
	else printf("%d", tot);
}