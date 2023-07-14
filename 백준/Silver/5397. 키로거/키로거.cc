#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		list<char> L;
		string s; cin >> s;
		list<char>::iterator it = L.begin();
		for (auto e : s) {
			if (e == '<') {
				if (it != L.begin()) it--;
			}
			else if (e == '>') {
				if (it != L.end()) it++;
			}
			else if (e == '-') {
				if (it != L.begin()) {
					it--;
					it = L.erase(it);
				}
			}
			else
				L.insert(it, e);
		}
		for (auto e : L)
			cout << e;
		cout << '\n';
	}
}