#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#define ll long long

using namespace std;
int ans[1000005];
int idx = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int,int>> stk;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		while (!stk.empty() && x > stk.top().first) {
			ans[stk.top().second] = x;
			stk.pop();
		}
		stk.push({ x,  idx++});
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) cout << -1 << ' ';
		else cout << ans[i] << ' ';
	}
}