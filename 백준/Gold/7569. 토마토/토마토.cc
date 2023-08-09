#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define X first
#define Y second

using namespace std;

int board[105][105][105];
int dist[105][105][105];
int nx[6] = { 0,0,1,0,-1,0 };
int ny[6] = { 0,0,0,1,0,-1 };
int nz[6] = { 1,-1,0,0,0,0 };

int M, N, H;
int ans;

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	queue<tuple<int,int,int>> Q;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			fill(dist[i][j], dist[i][j] + M, -1);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					Q.push({ i,j,k });
					dist[i][j][k] = 0;
				}
			}
		}
	}
	while (!Q.empty()) { // 0 1 2
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int dx = get<1>(cur) + nx[dir];
			int dy = get<2>(cur) + ny[dir];
			int dz = get<0>(cur) + nz[dir];
			if (dx < 0 || dx >= N || dy < 0 || dy >= M || dz < 0 || dz >= H) continue;
			if (board[dz][dx][dy] == -1 || dist[dz][dx][dy] >= 0) continue;
			Q.push({ dz,dx,dy });
			dist[dz][dx][dy] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[i][j][k] == 0 && dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}