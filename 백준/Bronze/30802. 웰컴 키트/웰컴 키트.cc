#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, T, P, a, b;
int tArr[10];
int sumation;
int ans1;

// https://www.acmicpc.net/problem/30802
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 6; i++) cin >> tArr[i];
	cin >> a >> b;

	for (int i = 0; i < 6; i++) {
		if (tArr[i] <= a && tArr[i] > 0) ans1 += 1;
		else if (tArr[i] % a == 0) ans1 += tArr[i] / a;
		else ans1 += tArr[i] / a + 1;
	}
	cout << ans1 << '\n' << (N / b) << ' ' << N % b;
}