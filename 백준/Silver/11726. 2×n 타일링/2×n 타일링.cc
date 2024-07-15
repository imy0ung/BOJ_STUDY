#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n;
int d[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1;
	d[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	cout << d[n];
}