#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define X first
#define Y second

using namespace std;

int dist[100001];

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	queue<int> Q;
	Q.push(N); dist[N] = 0;
	while (dist[K] == -1) {
		int cur = Q.front(); Q.pop();
		for (int nxt : {cur-1,cur+1,2*cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[K];
}