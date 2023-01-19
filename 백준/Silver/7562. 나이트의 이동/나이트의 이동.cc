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
int board[305][305];
int dis[305][305];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = { 1, 2, 2, 1, -1,-2,-2,-1 };
int N, S;
int x, y; // 말의 위치
int i, j; // 찾으려고 하는 위치

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		queue<pair<int, int>> Q;
		cin >> S;
		for (int t = 0; t < S; t++) fill(board[t], board[t] + S, 0);
		for (int t = 0; t < S; t++) fill(dis[t], dis[t] + S, -1);
		cin >> x >> y; // 출발
		Q.push({ x,y });
		dis[x][y] = 0;
		cin >> i >> j; // 도착
		while (dis[i][j] == -1) {
			auto cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = dx[dir] + cur.X;
				int ny = dy[dir] + cur.Y;
				if (nx < 0 || nx >= S || ny < 0 || ny >= S) continue;
				if (dis[nx][ny] >= 0) continue;
				dis[nx][ny] = dis[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}
		cout << dis[i][j] << '\n';
	}
}