#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];
int dist[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i,j });
				dist[i][j] = 0;
			}
		}
 	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] != -1 || board[nx][ny] == -1) continue;
			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && board[i][j] == 0) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}