#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define MAX 26

string map[MAX];
int visit[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N;
int ans = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i]; // map

	queue<pair<int,int>> Q;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visit[i][j] != 1) {
				int cnt = 0; // 단지 내 집의 수
				Q.push({ i,j });
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop(); cnt++;
					visit[cur.first][cur.second] = 1;

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (visit[nx][ny] == 1 || map[nx][ny] == '0') continue;
						visit[nx][ny] = 1; // 방문처리
						Q.push({ nx,ny }); // 큐에 넣어주기
					}
				}
				ans++; v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ans << '\n';
	for (int i = 0; i < ans; i++)
		cout << v[i] << '\n';
}