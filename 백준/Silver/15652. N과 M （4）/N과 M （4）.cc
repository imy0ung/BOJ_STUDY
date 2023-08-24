#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;
// 1 2 5 6

int n, m;
int ans[10];
int isused[10];

void func(int k, int st) {
	if (m == k) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = st; i <= n; i++) {
		if (!isused[i]) {
			ans[k] = i;
			func(k + 1, ans[k]);
		}
	}
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0,1);
}