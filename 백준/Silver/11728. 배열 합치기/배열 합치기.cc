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

int n, m;
int a[1000005], b[1000005], c[2000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int aidx = 0, bidx = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n + m; i++) {
		if (aidx == n) c[i] = b[bidx++]; // 남은거 털어주기1
		else if (bidx == m) c[i] = a[aidx++]; // 남은거 털어주기2
		else if (a[aidx] <= b[bidx]) c[i] = a[aidx++]; // 비교
		else c[i] = b[bidx++]; // 비교
	}
	for (int i = 0; i < n + m; i++) cout << c[i] << ' '; // 출력
}