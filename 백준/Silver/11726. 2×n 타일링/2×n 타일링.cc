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
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (d[x] != 0) return d[x];
	return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}
int main(void) {
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
}