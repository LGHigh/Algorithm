#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> a;
	for (int i = 0; i < 9; i++)a.push_back(i + 1);
	do {
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < 3; i++) {
			x = x * 10 + a[i];
			y = y * 10 + a[3 + i];
			z = z * 10 + a[6 + i];
		}
		if (x * 2 == y && x * 3 == z)
			printf("%d %d %d\n", x, y, z);
	} while (std::next_permutation(a.begin(),a.end()));
	return 0;
}