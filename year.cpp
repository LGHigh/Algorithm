#include <stdio.h>

int main() {
	int year;
	scanf_s("%d", &year);
	if (year % 4 != 0 || (year % 4 == 0 && year & 400 != 0))
		printf("yes");
	else printf("no");
	return 0;
}