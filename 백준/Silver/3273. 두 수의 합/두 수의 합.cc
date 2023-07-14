#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n, x, cnt;
int num[100005];
int arr[2000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		arr[num[i]]++;
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		arr[num[i]]--; // 중복방지
		if (x > num[i] && arr[x - num[i]] > 0) {
			cnt++;
		}
	}
	cout << cnt;
}