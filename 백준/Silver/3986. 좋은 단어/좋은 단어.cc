#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	while (n--) {
		stack<int> stk;
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (stk.empty())
				stk.push(s[i]);
			else if (stk.top() == s[i])
				stk.pop();
			else
				stk.push(s[i]);
		}
		if (stk.empty())
			ans++;
	}
	cout << ans;
}