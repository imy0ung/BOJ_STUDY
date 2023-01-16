#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <list>

using namespace std;

// iterator = container 내의 포인터
// refernce = 일종의 별명, 변수를 통해 같은 공간을 써서 메모리가 차지 x
// range - based for loop
// getlin(cin,s) -> 공백을 포함해서 받음

int main(void) {
	string a;
	stack<char> s;
	long long ans = 0;
	cin >> a;
	for (int idx = 0; idx < a.size(); idx++) {
		if (a[idx] == '(') s.push(a[idx]);
		else if (a[idx] == ')') {
			if (idx > 0 && a[idx - 1] == '(') {
				s.pop(); 
				ans += s.size();
			}
			else { // 마지막 막대는 잘린거랑 다름없음으로...!!
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}
// 10799
// 2504