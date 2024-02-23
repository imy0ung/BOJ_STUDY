#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#pragma warning (disable : 4996)

using namespace std;

int stair[301];
int dp[301];

int main()
{
	int n, i;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = max(stair[1] + stair[2], stair[2]);

	for (i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i-1] + stair[i]);
	}

	printf("%d", dp[n]);
}