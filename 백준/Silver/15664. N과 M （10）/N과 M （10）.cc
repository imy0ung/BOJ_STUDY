#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int arr[10];
int isused[10];
int ans[10];

void func(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = st; i < n; i++) {
		if (!isused[i] && tmp != arr[i]) {
			isused[i] = 1;
			ans[k] = arr[i];
			tmp = arr[i];
			func(k + 1, i + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0,0);
}