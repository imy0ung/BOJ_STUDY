#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, k, ans;
int rope[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> rope[i];
	sort(rope, rope + N);
	// k개의 줄을 사용한다면,
	for (int i = 1; i <= N; i++) {
		ans = max(ans, rope[N - i] * i);
	}
	cout << ans;
}