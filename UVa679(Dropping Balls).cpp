/*
本题不能直接用树的方法进行编写，否则会无限超时
应该找出第n个数字和所在位置在二进制中的共同点
通过位运算进行编写
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int cnt;
	scanf("%d", &cnt);
	while (cnt--) {
		int depth, num;
		scanf("%d%d", &depth, &num); num--; depth--;
		int now = 1;
		for (int i = 0; i < depth;i++) {
			if (num & 1)
				now = (now << 1) + 1;
			else now <<= 1;
			num >>= 1;
		}
		printf("%d\n", now);
	}
	cin >> cnt;
	return 0;
}