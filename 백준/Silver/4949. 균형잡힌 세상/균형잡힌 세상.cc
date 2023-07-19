#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		stack<int> stack;
		string s;
		int flag = 0;
		getline(cin,s);
		if (s == ".") break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[')
				stack.push(s[i]);
			else if (s[i] == ')') {
				if (stack.empty()) {
					flag = 1; break;
				}
				else if (stack.top() == '(')
					stack.pop();
				else {
					flag = 1; break;
				}
			}
			else if (s[i] == ']') {
				if (stack.empty()) {
					flag = 1; break;
				}
				else if (stack.top() == '[')
					stack.pop();
				else {
					flag = 1; break; // (])
				}
			}
		}

		if (flag == 1)
			cout << "no\n";
		else if (stack.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}