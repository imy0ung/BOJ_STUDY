#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define X first
#define Y second
#define ll long long int
using namespace std;

ll a, b, c;

int func(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll k = func(a, b / 2, c);
	k = (k * k) % c;
	if (b % 2 == 0)
		return k;
	else 
		return k * a % c;
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << func(a, b, c);
}