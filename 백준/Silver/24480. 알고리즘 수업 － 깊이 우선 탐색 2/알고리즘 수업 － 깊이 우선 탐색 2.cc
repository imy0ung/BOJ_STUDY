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

vector<int> v[100001];
int ans[100001];
int visited[100001];
int cnt = 1;

void dfs(int start) {
	if (visited[start]) return; // 방문한 노드면 종료
	visited[start] = true; // 방문처리 해준다.
	ans[start] = cnt++; // 답코드에 순서 넣어주고

	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i]])
			dfs(v[start][i]); // 인접노드순회하면서, 스택형식으로 dfs 수행
	}
}

bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main(void) {
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); // 노드를 연결해준다.
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), compare); // 각 노드의 인접노드들을 내림차순으로 정렬해준다.
	}

	dfs(R); // dfs 실행

	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n'; // 답 출력
}