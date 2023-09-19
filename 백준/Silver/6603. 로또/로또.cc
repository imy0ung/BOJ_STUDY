#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;
int S[55];
int ans[55];
int isused[55];
int k;

void func(int d, int st) {
	if (d == 6) {
		for (int i = 0; i < 6; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = st; i < k; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			ans[d] = S[i];
			func(d + 1, i);
			isused[i] = 0;
		}
	}
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> k;
		if (k == 0)  break;
		for (int i = 0; i < k; i++)
			cin >> S[i];
		func(0,0);
		cout << '\n';
	}
}