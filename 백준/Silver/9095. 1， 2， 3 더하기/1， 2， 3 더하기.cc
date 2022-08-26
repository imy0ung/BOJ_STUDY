#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#pragma warning (disable : 4996)

using namespace std;

int d[1000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	d[1] = 1; d[2] = 2; d[3] = 4;


	while(n--) {
		int x; cin >> x;
		for (int i = 4; i <= x; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[x] <<'\n';
	}
}