#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define MAX 51

int map[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int T,M,N,K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T; //test case

	for (int i = 0; i < T; i++) {
		int ans = 0;
		queue<pair<int, int>> Q;
		cin >> M >> N >> K;

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				map[j][k] = 0; // map 초기화
				visit[j][k] = 0; // 방문 노드 초기화
			}
		}
		for (int j = 0; j < K; j++) {
			int x, y; 
			cin >> x >> y;
			map[x][y] = 1;
		} // 배추의 위치 조사

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == 1 && visit[j][k] != 1) {
					Q.push({ j,k });
					visit[j][k] = 1;
					ans++;
				}
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue; // 범위초과될경우
						if (map[nx][ny] == 0 || visit[nx][ny] == 1) continue; // 방문한 노드거나 벽이거나
						Q.push({ nx,ny }); // 해당 노드 집어넣어주고
						visit[nx][ny] = 1; // 방문처리해주고
					}
				}
			}
		}
		cout << ans << '\n';
	}
}