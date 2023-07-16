#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n;
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (1) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		int top = q.front();
		q.pop();
		q.push(top);
	}
}