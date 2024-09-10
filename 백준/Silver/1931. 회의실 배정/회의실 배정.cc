#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, ans, t;
pair<int, int> arr[100005];

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		if (t > arr[i].first) continue;
		ans++;
		t = arr[i].second;
	}
	cout << ans;
}