#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int THR = 3;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (THR--) {
		for (int i = 0; i < 4; i++) {
			int Y;
			cin >> Y;
			if (Y == 0) cnt++;
		}
		if (cnt == 1) cout << "A\n";
		if (cnt == 2) cout << "B\n";
		if (cnt == 3) cout << "C\n";
		if (cnt == 4) cout << "D\n";
		if (cnt == 0) cout << "E\n";
		cnt = 0;
	}
}