#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#define ll long long

using namespace std;

int K;

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	func(6 - a - b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	cout << (1<<K) -1 << '\n';
	func(1, 3, K);
}