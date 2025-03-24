#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <tuple>
#define ll long long

using namespace std;

int d[505][505];
int arr[505][505];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			cin >> arr[i][j];
	}
	d[1][0] = arr[1][0];
	for (int k = 1; k <= n; k++) {
		for (int j = 0; j < k; j++) {
			if (j == 0) d[k][j] = d[k - 1][0] + arr[k][j];
			else if (j == k) d[k][j] = d[k - 1][k - 1] + arr[k][j];
			else d[k][j] = max(d[k - 1][j - 1], d[k - 1][j]) + arr[k][j];
		}
	}
	cout << *max_element(d[n], d[n] + n);
}