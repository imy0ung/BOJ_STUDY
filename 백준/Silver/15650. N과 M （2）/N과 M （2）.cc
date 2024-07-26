#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int isused[10];
int arr[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int st = 1;
	if (k!= 0) st = arr[k- 1] + 1;
	for (int i = st; i <= n; i++) {
		if (isused[i]) continue;
		isused[i] = 1;
		arr[k] = i;
		func(k + 1);
		isused[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	func(0);
}