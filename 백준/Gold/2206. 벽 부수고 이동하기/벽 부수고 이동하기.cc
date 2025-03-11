#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

// 벽을 안뚫고 갔을 때와 뚫고 갔을 때의 최단 거리를 비교하면?
// 벽이 없는 세계 와 벽이 있는 세계를 만들자
// 어차피 bfs는 최단 거리를 구하는 거니까 다른 경우의 수를 생각안해도 된다.
int N, M;
string board[1005];
int dist[1005][1005][2];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<tuple<int, int, int>> q;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> board[i];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    if (board[0][0] == '0') {
        if (N == 1 && M == 1) {
            cout << 1;
            return 0;
        }
        q.push({ 0,0,0 });
        dist[0][0][0] = 0;
    }
    else {
        cout << 1;
        return 0;
    }

    while (!q.empty()) {
        int first, second, world;
        tie(first,second,world) = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = first + dx[dir];
            int ny = second + dy[dir];
            if (nx == N - 1 && ny == M - 1) {
                cout << dist[first][second][world] + 2 << '\n';
                return 0;
            }
            if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][world] == -1) {
                q.push({ nx,ny,world });
                dist[nx][ny][world] = dist[first][second][world] + 1;
            }

            // 벽을 뚫는 경우..
            if (world == 0 && board[nx][ny] == '1' && dist[nx][ny][0] == -1) {
                q.push({ nx,ny,1 });
                dist[nx][ny][1] = dist[first][second][0] + 1;
            }
        }
    }
    cout << -1;
    return 0;
}