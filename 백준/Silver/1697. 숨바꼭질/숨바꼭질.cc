#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define MAX 1000

int visit[200001];
int mv[2] = { -1,1 };
int N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K; // 수빈의 현위치와 동생의 현위치
	queue<int> Q;
	fill(visit, visit + 200001, -1);
	Q.push(N); visit[N] = 0;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 2; dir++) {
			int mover = cur + mv[dir];
			if (mover < 0 || mover > 200000 || visit[mover] > -1) continue;
			Q.push(mover);
			visit[mover] = visit[cur] + 1;
		} // 왼쪽 오른쪽

		int mover = cur * 2;
		if (mover < 0 || mover > 200000 || visit[mover] > -1) continue;
		Q.push(mover);
		visit[mover] = visit[cur] + 1; // 순간이동하는 경우도 
		
		if (mover == K) {
			break;
		} // 찾으면 break;
	}
	cout << visit[K];
}