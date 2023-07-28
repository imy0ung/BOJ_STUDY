#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define X first
#define Y second

using namespace std;

int MAP[505][505];
int vis[505][505];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
int num, mx;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> MAP[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 0 || vis[i][j]) continue;
			num++;
			queue <pair<int, int>> Q;
			int sqr = 0;
			Q.push({ i,j });
			vis[i][j] = 1;
			while (!Q.empty()) {
				sqr++;
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || MAP[nx][ny] == 0) continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
			mx = max(sqr, mx);
		}
	}
	cout << num << '\n' << mx;
}