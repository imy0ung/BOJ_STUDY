#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int vis[30];
int cnt;

void func(int k, int tot) {
	if (k == n) {
		if (tot == s) cnt++;
		return;
	}
	func(k + 1, tot);
	func(k + 1, tot + arr[k]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}