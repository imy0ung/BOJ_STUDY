#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

// deque vs vector

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	deque<int> dq;

	while (n--) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int x; cin >> x;
			dq.push_front(x);
		}
		else if (s == "push_back") {
			int x; cin >> x;
			dq.push_back(x);
		}
		else if (s == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << '\n';
		}
		else if (s == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (s == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else  {
			if (dq.empty())
				cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}