#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int isused[10];
int arr[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int st = 1;
	if (st != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= n; i++) {
		if (isused[i]) continue;
		arr[k] = i;
		isused[i] = 1;
		func(k + 1);
		isused[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}