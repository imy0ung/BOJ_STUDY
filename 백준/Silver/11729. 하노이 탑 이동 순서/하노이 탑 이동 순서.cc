#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define X first
#define Y second
#define ll long long int
using namespace std;

int s, f, n;

void func(int s, int f, int n) {
	if (n == 1) {
		cout << s << ' ' << f << '\n';
		return;
	}
	func(s, 6-s-f, n - 1);
	cout << s << ' ' << f << '\n';
	func(6-s-f, f, n - 1);
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	cout << (1 << N) - 1 << '\n';
	func(1, 3, N);
}