#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define MAX 1005

int board[MAX][MAX];
int dis[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push({ i,j });
			if (board[i][j] == 0)
				dis[i][j] = -1;
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 초과 제한
			if (board[nx][ny] == -1 || dis[nx][ny] >= 0) continue; // 방문하거나, 벽이거나
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			Q.push({ nx,ny }); // 넣어주고 반복
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (dis[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(dis[i][j], ans);
		}
	}

	cout << ans;
}