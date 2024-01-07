#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

double W, H, N, M;

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W >> N >> M;

	cout << (long long) ceil((H / (N + 1))) * (long long)ceil((W / (M + 1)));
}