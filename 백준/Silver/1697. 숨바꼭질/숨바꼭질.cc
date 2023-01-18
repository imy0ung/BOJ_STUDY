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
int dist[100002];
int n, k;
queue<int> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0; 
	Q.push(n);
	while (dist[k] == -1) {
		auto cur = Q.front(); Q.pop();
		for (auto t : { cur + 1, cur - 1, cur * 2 }) {
			if (t < 0 || t > 100000) continue;
			if (dist[t] != -1) continue;
			dist[t] = dist[cur] + 1;
			Q.push(t);
		}
	}
	cout << dist[k];
}