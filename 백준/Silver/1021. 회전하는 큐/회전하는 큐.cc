#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

// deque vs vector

int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	while (m--) {
		int x, idx = 0;
		cin >> x;
		for (int i = 0; i < dq.size(); i++)
			if (dq[i] == x)
				idx = i;

		while (dq.front() != x) {
			if (dq.size() - idx <= dq.size() / 2) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
			else {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans;
}