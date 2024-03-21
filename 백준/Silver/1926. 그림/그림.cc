#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int board[501][501];
int vis[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;
int ans;
int cnt;
queue<pair<int, int>>Q;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && vis[i][j] != 1) {
                int area = 0;
                Q.push({ i,j });
                vis[i][j] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({ nx,ny });
                    }
                }
                cnt++;
                ans = max(area, ans);
            }
        }
    }
    cout << cnt << '\n' << ans;
    return 0;
}