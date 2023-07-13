#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int arr[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;

	cin >> A >> B >> C;
	int ans = A * B * C;
	while (ans >= 1) {
		arr[ans%10]++;
		ans = ans / 10;
	}
	for (auto e : arr)
		cout << e << '\n';
}