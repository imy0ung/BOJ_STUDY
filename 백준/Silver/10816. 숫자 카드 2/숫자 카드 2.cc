#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	int N, M;
	vector<int> a, b;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < M; i++) {
		cout << upper_bound(a.begin(), a.end(), b[i]) - lower_bound(a.begin(), a.end(), b[i]) << ' ';
	}
}