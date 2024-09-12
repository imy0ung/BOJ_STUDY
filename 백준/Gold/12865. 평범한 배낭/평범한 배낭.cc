#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[100005];
int V[1005];
int d[105][100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= W[i]) // 물건을 넣을 수 있는 경우
				d[i][j] = max(d[i - 1][j], d[i - 1][j - W[i]] + V[i]);
			else // 물건을 넣을 수 없는 경우
				d[i][j] = d[i - 1][j];
		}
	}

	cout << d[N][K];
}