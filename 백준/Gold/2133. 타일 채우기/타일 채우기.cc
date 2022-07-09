#include <iostream>
#include <algorithm>
#include <vector> // pair library
#include <stack>
#include <queue>
#include <cmath>
#pragma warning(disable:4996)

using namespace std; //dynamic program

int d[1001];

int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	int result = 3 * dp(x - 2);
	for (int i = 4; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp(x - i );
		}
	}
	return d[x] = result;
}

int main(void) {
	int x;
	scanf("%d", &x);
	printf("%d\n",dp(x));
}