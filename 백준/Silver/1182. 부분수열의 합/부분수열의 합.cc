#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n, s, cnt;
int arr[100];

void func(int k, int tot) {
	if (k == n) {
		if (tot == s) cnt++;
		return;
	}
	func(k + 1, tot); // 수를 선택하지 않은 경우
	func(k + 1, arr[k] + tot); // 수를 선택한 경우
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}