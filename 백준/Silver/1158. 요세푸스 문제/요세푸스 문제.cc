#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n, k, cnt;
queue<int> q;
vector<int> ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cnt = n;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (n--) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}
	cout << '<';
	for (int i = 0; i < cnt; i++) {
		if (i == cnt - 1)
			cout << ans[i];
		else cout << ans[i] << ',' << ' ';
	}
	cout << '>';
}