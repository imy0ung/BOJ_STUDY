#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define MAX 1000

int map[MAX][MAX];
int dis[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		fill(dis[i], dis[i + m + 1], -1);
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 }); dis[1][1] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= m + 1) continue;
			if (dis[nx][ny] > -1 || map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
		}
	}

	cout << dis[n][m] + 1;

	return 0; 
}