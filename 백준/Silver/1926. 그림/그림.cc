#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

#define MAX 500

int board[MAX][MAX];
int visit[MAX][MAX];
int cnt = 0;
queue <pair<int, int>> Q;

int dx[4] = { 1,0,-1,0 }; // 상하
int dy[4] = { 0,1,0,-1 }; // 좌우

int main(void) {
	int n, m;
	int mx = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 1 || visit[i][j]) continue;
			cnt++;
			Q.push({ i,j });
			visit[i][j] = 1;
			int area = 0;
			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny] || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << '\n' << mx;
}