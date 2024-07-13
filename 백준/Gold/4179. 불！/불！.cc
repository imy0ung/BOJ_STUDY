#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string board[1005];
int fdist[1005][1005];
int jdist[1005][1005];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	// dist 초기화
	for (int i = 0; i < n; i++) fill(fdist[i], fdist[i] + m, -1);
	for (int i = 0; i < n; i++) fill(jdist[i], jdist[i] + m, -1);
	
	// 입력
	for (int i = 0; i < n; i++) cin >> board[i];
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				Q.push({ i,j });
				fdist[i][j] = 0;
			}
		}
	}
	// 불 bfs
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '#' || fdist[nx][ny] != -1) continue;
			Q.push({ nx,ny });
			fdist[nx][ny] = fdist[cur.first][cur.second] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				Q.push({ i,j });
				jdist[i][j] = 0;
			}
		}
	}

	// 지훈이 bfs
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				cout << jdist[cur.first][cur.second] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || jdist[nx][ny] != -1) continue;
			if (jdist[cur.first][cur.second] + 1 >= fdist[nx][ny] && fdist[nx][ny] != -1) continue;
			Q.push({ nx,ny });
			jdist[nx][ny] = jdist[cur.first][cur.second] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}