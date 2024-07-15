#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int freq[2000005];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x += 1000000;
		freq[x]++;
	}
	for (int i = 0; i < 2000005; i++) {
		while (freq[i] > 0) {
			cout << i - 1000000 << '\n';
			freq[i]--;
		}
	}
}