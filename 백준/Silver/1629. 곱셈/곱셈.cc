#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#define ll long long

using namespace std;

ll A, B, C;

ll func(ll a, ll b, ll m) {
	if (b == 1) return a % m;
	ll val = func(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return val;
	return val * a % m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;
	cout << func(A, B, C);
}