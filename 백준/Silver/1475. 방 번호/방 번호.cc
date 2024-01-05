#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int card[10] ;
int ans;

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	while (a != 0) {
		int k = a % 10;
		a = a / 10;
		if (card[k] == 0) {
			if (k == 6 && card[9] > 0) {
				card[9]--;
				continue;
			}
			if (k == 9 && card[6] > 0) {
				card[6]--;
				continue;
			}
			for (int i = 0; i < 10; i++)
				card[i]++;
			ans++;
		}
		card[k]--;
	}
	cout << ans;
}