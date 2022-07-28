#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}

int main(void) {
	int N, M;
	int* parent;
	scanf("%d %d", &N, &M);

	parent = (int *)calloc(N + 1, sizeof(int));

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int com, a, b;
		scanf("%d %d %d", &com, &a, &b);

		if (com == 0) {
			unionParent(parent, a, b);
		}
		else if (com == 1) {
			if (findParent(parent, a, b) == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}