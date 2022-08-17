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
using ll = long long;

ll mod(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll val = mod(a, b / 2, m);
	val = (val * val) % m;
	if (b % 2 == 0) return val;
	else 
		return val * a % m;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	cout << mod(A, B, C);
}