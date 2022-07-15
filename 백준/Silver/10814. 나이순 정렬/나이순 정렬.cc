#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

bool compare(pair<int, pair<int, string>> v1, pair<int, pair<int, string>> v2) {
	if (v1.second.first == v2.second.first) {
		return v1.first < v2.first;
	}
	else {
		return v1.second.first < v2.second.first;
	}
}

int main(void) {
	int n;
	vector<pair<int, pair<int, string>>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int age;
		cin >> age >> name;
		v.push_back(pair<int,pair<int,string>>(i, make_pair(age, name)));
	}
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].second.first << ' ' << v[i].second.second << '\n';
	}
}