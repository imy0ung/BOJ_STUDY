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

string board[1005];
int Sdist[1005][1005];
int Fdist[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int T;
int W, H;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		queue<pair<int, int>> QF = {};
		queue<pair<int, int>> QS = {};
		int success = 0;
		cin >> W >> H;
		for (int i = 0; i < H; i++)
			cin >> board[i];
		for (int i = 0; i < H; i++) fill(Sdist[i], Sdist[i] + W, -1);
		for (int i = 0; i < H; i++) fill(Fdist[i], Fdist[i] + W, -1);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (board[i][j] == '*') {
					Fdist[i][j] = 0;
					QF.push({ i,j });
				}
				if (board[i][j] == '@') {
					Sdist[i][j] = 0;
					QS.push({ i,j });
				}
			}
		} // 불이 난 위치를 푸쉬
		while (!QF.empty()) {
			auto cur = QF.front();
			QF.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = dx[dir] + cur.X;
				int ny = dy[dir] + cur.Y;
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (board[nx][ny] == '#' || Fdist[nx][ny] >= 0) continue;
				Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
				QF.push({ nx,ny });
			}
		}
		while (!QS.empty() && !success) {
			auto cur = QS.front();
			QS.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = dx[dir] + cur.X;
				int ny = dy[dir] + cur.Y;
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
					cout << Sdist[cur.X][cur.Y] + 1 << '\n';
					success = 1;
					break; // 미로에서 탈출했음을 의미
				}
				if (board[nx][ny] == '#' || Sdist[nx][ny] >= 0) continue;
				if (Fdist[nx][ny] != -1 && Sdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny]) continue;
				Sdist[nx][ny] = Sdist[cur.X][cur.Y] + 1;
				QS.push({ nx,ny });
			}
		}
		if (!success)
			cout << "IMPOSSIBLE" << '\n';
	}
}