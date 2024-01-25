#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

string board[1002];
int Fdist[1002][1002];
int Jdist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C;
queue<pair<int, int>>Q1;
queue<pair<int, int>>Q2;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    for (int i = 0; i < R; i++) fill(Fdist[i], Fdist[i] + C, -1);
    for (int i = 0; i < R; i++) fill(Jdist[i], Jdist[i] + C, -1);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'F') {
                Q1.push({ i,j });
                Fdist[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                Q2.push({ i,j });
                Jdist[i][j] = 0;
            }
        }
    }
    while (!Q1.empty()) {
        auto cur = Q1.front(); 
        Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == '#' || Fdist[nx][ny] > -1) continue;
            Q1.push({ nx,ny });
            Fdist[nx][ny] = Fdist[cur.first][cur.second] + 1;
        }
    }

    while (!Q2.empty()) {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << Jdist[cur.first][cur.second] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || Jdist[nx][ny] > -1) continue;
            if (Fdist[nx][ny] != -1 && Jdist[cur.first][cur.second] + 1 >= Fdist[nx][ny]) continue;
            Q2.push({ nx,ny });
            Jdist[nx][ny] = Jdist[cur.first][cur.second] + 1;
        }
    }


    cout << "IMPOSSIBLE";
    return 0;
}