#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

//counting sort
//숫자 범위가 주어졌을 때, 가장 빠른 알고리즘
using namespace std;

int n;
string s[20001];

bool compare(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length())
		return a < b;
	else
		return false;
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, compare);

	for (int i = 0; i < n; i++) {
		if (s[i] == s[i + 1])
			continue;
		cout << s[i] << '\n';
	}
}