#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include<cstring>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	int n;
	int x;
	cin >> n;
	priority_queue <int> pq;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != 0)
			pq.push(-x);
		else {
			if (!pq.empty()) {
				int ans = pq.top();
				printf("%d\n", -ans);
				pq.pop();
			}
			else
				printf("0\n");
		}
	}
}