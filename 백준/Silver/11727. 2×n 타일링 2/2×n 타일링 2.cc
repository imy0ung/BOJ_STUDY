#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <tuple>
#define ll long long

using namespace std;

int d[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	d[1] = 1; d[2] = 3;
	for (int k = 3; k <= 1000; k++) {
		d[k] = (d[k - 1] + d[k - 2] + d[k - 2]) % 10007;
	}
	cout << d[n];
}