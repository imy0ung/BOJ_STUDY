#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
int dist[105][105];

void bfs(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> Q;
    for (int i = 0; i < n; i++) fill (dist[i], dist[i] + m, -1);
    Q.push({0,0}); dist[0][0] = 0;
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    bfs(maps);
    int answer = 0;
    if (dist[n-1][m-1] != -1) answer = dist[n-1][m-1] + 1;
    else answer = -1;
    return answer;
}