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

int N;
int ans1, ans2;
string board[105];
int vis[105][105];
int nx[4] = { 1, 0, -1, 0 };
int ny[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;


// bfs를 3번 돌려야할까?

void bfs(int i, int j, char x, queue<pair<int,int>> q1, int flag) {
	vis[i][j] = 1; q1.push({ i,j });
	while (!q1.empty()) {
		auto cur = q1.front(); 
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int dx = cur.X + nx[i];
			int dy = cur.Y + ny[i];
			if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
			if (flag == 0) {
				if (vis[dx][dy] || board[dx][dy] != x) continue;
			}
			else {
				if (vis[dx][dy] || board[dx][dy] == 'B') continue;
			}
			vis[dx][dy] = 1;
			q1.push({ dx,dy });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'R' && !vis[i][j]) {
				bfs(i, j, 'R', Q1, 0);
				ans1++;
			}
			if (board[i][j] == 'G' && !vis[i][j]) {
				bfs(i, j, 'G', Q1, 0);
				ans1++;
			}
			if (board[i][j] == 'B' && !vis[i][j]) {
				bfs(i, j, 'B', Q1, 0);
				ans1++;
			}
		}
	}
	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((board[i][j] == 'R' || board[i][j] == 'G') && !vis[i][j]) {
				bfs(i, j, 'R', Q2, 1);
				ans2++;
			}

			if (board[i][j] == 'B' && !vis[i][j]) {
				bfs(i, j, 'B', Q2, 0);
				ans2++;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}