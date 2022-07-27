#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

//DFS(Depth First Search)

/*
* 큐에서 하나의 노드를 꺼내고,
* 해당 노드에서 방문하지 않은 인접노드를 스택에 넣고 방문처리해줌.
*/

using namespace std;

vector<int> v[200001];
int ans[200001];
int c[200001]; // check array
int num = 1; // ordrer

void dfs(int start) {
	if (c[start]) return;
	c[start] = true;
	ans[start] = num++;
	for (int i = 0; i < v[start].size(); i++) {
		int x = v[start][i];
		if (!c[x])
			dfs(x);
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

	for (int i = 0; i < N; i++)
		sort(v[i].begin(), v[i].end());

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}