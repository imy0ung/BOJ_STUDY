#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N = 5;
int a;
int ans_sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (N--) {
		cin >> a;
		ans_sum += a * a;
	}

	cout << ans_sum % 10;
}