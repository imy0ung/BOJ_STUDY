#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

int N;
int heap[100002];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		int parent = idx / 2;
		if (heap[parent] <= heap[idx]) break;
		swap(heap[parent], heap[idx]);
		idx = parent;
	}
}

int top() {
	return heap[1];
}

void pop() {
	heap[1] = heap[sz--];
	int idx = 1;
	while (2 * idx <= sz) {
		int lc = 2 * idx, rc = 2 * idx + 1;
		int min_child = lc;
		if (rc <= sz && heap[rc] < heap[lc])
			min_child = rc;
		if (heap[idx] <= heap[min_child]) break;
		swap(heap[idx], heap[min_child]);
		idx = min_child;
	}
}

void test() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);

		if (x == 0) {
			if (sz > 0) {
				printf("%d\n", top());
				pop();
			}
			else printf("0\n");
		}
		else {
			push(x);
		}
	}
}

int main(void) {
	test();
}