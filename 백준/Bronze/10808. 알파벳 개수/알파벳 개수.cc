#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int arr[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; 
	cin >> s;

	for (auto e : s)
		arr[e - 'a']++;
	for (auto e : arr)
		cout << e << ' ';
}