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

int map[1000005];
int dx[2];
int dist[1000005];
queue<int> Q;
int F, S, G, U, D;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	// F는 건물 층수, S 현위치, G는 가고자하는위치 
	fill(dist, dist + F + 1, -1);
	Q.push(S); dist[S] = 0;
	dx[0] = U; dx[1] = -D;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		if (cur == G) {
			cout << dist[cur];
			return 0;
		}
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx <= 0 || nx > F) continue;
			if (dist[nx] >= 0) continue;
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	cout << "use the stairs";
}