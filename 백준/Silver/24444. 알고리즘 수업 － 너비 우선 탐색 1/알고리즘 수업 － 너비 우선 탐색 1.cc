#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

vector<int> v[100001];
int visited[100001];
int ans[100001];
int cnt = 1;

void bfs(int start) {
	queue<int> q;
	q.push(start); // 첫 노드를 q에 넣어준다.
	visited[start] = true; // 방문처리 해준다.

	while (!q.empty()) { // 큐가 빌 때까지,
		int x = q.front();
		q.pop();
		ans[x] = cnt++; 
		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]]) { // 방문하지 않은 노드는 
				visited[v[x][i]]= true;
				q.push(v[x][i]); // 큐에 push해준다.
			}
		}
	}
}

int main(void) {
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	bfs(R);

	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}