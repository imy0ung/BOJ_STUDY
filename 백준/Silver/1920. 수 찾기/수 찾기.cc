#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> k;
	while (k--) {
		int f;
		cin >> f;
		cout << binary_search(arr, arr + n, f) << '\n';
	}
}