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

int postive_freq[1000001];
int negative_freq[1000001];
int arr[1000001];
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] >= 0) postive_freq[arr[i]]++;
		if (arr[i] < 0) negative_freq[-arr[i]]++;
	}
	for (int i = 1000000; i > 0; i--) {
		if (negative_freq[i] != 0) {
			for (int j = 0; j < negative_freq[i]; j++)
				cout << -i << '\n';
		}
	}
	for (int i = 0; i < 1000001; i++) {
		if (postive_freq[i] != 0) {
			for (int j = 0; j < postive_freq[i]; j++)
				cout << i << '\n';
		}
	}
}