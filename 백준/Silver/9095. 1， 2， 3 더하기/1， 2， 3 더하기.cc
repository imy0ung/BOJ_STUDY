#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
// d[k] = d[k-1] + d[k-2] + 1
int d[100];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << d[x] << '\n';
	}

}