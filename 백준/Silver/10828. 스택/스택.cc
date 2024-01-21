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

stack<int> s;
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string c;
		cin >> c;
		if (c == "push") {
			int x; cin >> x;
			s.push(x);
		}
		if (c == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		if (c == "size") {
			cout << s.size() << '\n';
		}
		if (c == "empty") {
			cout << (int)s.empty() << '\n';
		}
		if (c == "top") {
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}