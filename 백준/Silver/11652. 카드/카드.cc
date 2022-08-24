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

long long arr[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; int cnt = 0; int mxcnt = 0;
	long long mxval =  -(1ll << 62) - 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i == 0 || arr[i] == arr[i - 1])
			cnt++;
		else {
			if (mxcnt < cnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mxcnt) mxval = arr[n - 1];
	cout << mxval;
}