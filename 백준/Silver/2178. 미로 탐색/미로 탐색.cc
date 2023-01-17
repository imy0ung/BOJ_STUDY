#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <list>

#define X first
#define Y second

using namespace std;

string board[105];
int dis[105][105]; // 거리
int dx[4] = {1, 0 ,-1, 0}; // 행
int dy[4] = {0, 1, 0, -1}; // 열
int n, m;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) fill(dis[i], dis[i] + m, - 1);
	queue<pair<int, int>> Q;
	dis[0][0] = 0;
	Q.push({ 0,0 });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' || dis[nx][ny] >= 0) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dis[n - 1][m - 1] + 1;
}