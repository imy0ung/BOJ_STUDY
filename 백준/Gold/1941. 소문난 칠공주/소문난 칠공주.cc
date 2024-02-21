#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

bool mask[25]; // combination을 위한 mask
int ans;
int nx[4] = {-1,0,1,0};
int ny[4] = { 0,-1,0,1 };
string board[5];

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }
    fill(mask + 7, mask + 25, true);
    // bfs 수행
    do {
        queue<pair<int, int>> q;
        int dasom = 0; // 다솜파는 몇명일까..?
        int adj = 0; // 인접한 수
        bool check[5][5] = {}, isp7[5][5] = {};
        for (int i = 0; i < 25; i++) {
            if (!mask[i]) {
                int x = i / 5;
                int y = i % 5;
                isp7[x][y] = true;
                if (q.empty()) {
                    q.push({ x,y });
                    check[x][y] = 1;
                }
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            adj++;
            if (board[cur.first][cur.second] == 'S') dasom++;
            for (int dir = 0; dir < 4; dir++) {
                int dx = cur.first + nx[dir];
                int dy = cur.second + ny[dir];
                if (dx < 0 || dx >= 5 || dy < 0 || dy >= 5) continue;
                if (check[dx][dy] == 1 || !isp7[dx][dy]) continue;
                check[dx][dy] = 1;
                q.push({ dx,dy });
            }
        }
        if (adj >= 7 && dasom >= 4) ans++;
    } while (next_permutation(mask,mask+25));
    cout << ans;
}