#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int arr[100005];
int d[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	d[0] = arr[0];

	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + arr[i];
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << d[y] - d[x] + arr[x] << '\n';
	}
}
