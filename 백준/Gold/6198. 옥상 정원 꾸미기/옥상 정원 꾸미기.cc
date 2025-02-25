#include <iostream>	
#include <algorithm>
#include <list>
#include <stack>
#define ll long long

using namespace std;
ll ans;
// stack을 뷰를 볼 수 있는 건물이라 생각하고 업데이트
// 스택에 건물이 들어오기 전에 검사해서, 결국엔 순차적으로 건물을 셀 수 있음
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<ll> stk;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		while (!stk.empty() && stk.top() <= x) {
			stk.pop();
		}
		ans += stk.size();
		stk.push(x);
	}
	cout << ans;
}