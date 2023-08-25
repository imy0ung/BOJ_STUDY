#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;
// 1 2 5 6

int n, m;
int ans[10];
int arr[10];
int isused[10000];

void func(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = st; i < n; i++) {
		if (!isused[arr[i]]) {
			ans[k] = arr[i];
			isused[arr[i]] = 1;
			func(k + 1, i + 1);
			isused[arr[i]] = 0;
		}
	}
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0, 0);
}