#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

int findParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	if (parent[a] == parent[b])
		return 1;
	else return 0;
}

int main(void) {
	int N, M;
	int* city, *visit;

	cin >> N >> M;

	city = (int*)calloc(N + 1, sizeof(int));
	visit = (int*)calloc(M, sizeof(int));
	
	for (int i = 1; i <= N; i++)
		city[i] = i; // 도시의 이름


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x; scanf("%d", &x);
			if (x == 1) {
				unionParent(city, i, j);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> visit[i];
	}

	for (int i = 0; i < M; i++) {
		if (i <= M - 2 && findParent(city, visit[i], visit[i + 1]) == 0) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}