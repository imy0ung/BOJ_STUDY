#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

stack<pair<int,int>> s;
int n, x; 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	s.push({ 100000005,0 });
	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		while (s.top().first <= x)
			s.pop();
		cout << s.top().second << ' ';
		s.push({ x, i });
	}
}