#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int board[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
queue<pair<int, int>>Q;
int day;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < m; i++) fill(dist[i], dist[i] + n, -1);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1 || board[i][j] == 0 || dist[i][j] > -1) continue;
            Q.push({ i,j }); 
            dist[i][j] = 0;
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] > -1 || board[nx][ny] == -1) continue;
            Q.push({ nx, ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && board[i][j] == 0) {
                // 토마토는 있는데, 익지않은상황
                cout << -1;
                return 0;
            }
            day = max(dist[i][j], day);
        }
    }
    cout << day;
    return 0;
}