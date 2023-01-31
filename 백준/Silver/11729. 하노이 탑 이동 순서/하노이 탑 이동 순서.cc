#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <list>

#define X first
#define Y second
// 보통 1억에 1초 
// TC가 10만기준으로 O(N)은 1/1000초
// TC가 10만기준으로 O(N^2)은 100억 , 100초
// TC가 105*105
using namespace std;

void hanoi(int s, int f, int n) {
	if (n == 1) {
		cout << s << ' ' << f << '\n'; // base condition
		return;
	}
	hanoi(s, 6 - s - f, n - 1);
	cout << s << ' ' << f << '\n'; // 원판을 옮긴다.
	hanoi(6 - s - f, f, n - 1); // 마지막으로 옮긴다.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; 
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // rightshift로 옮겨라
	hanoi(1, 3, n);
}

// 원판 하나를 구할 수 있다.
// 원판이 k개 일때는 k-1만큼의 원판을 기둥 2에 옮기고,
// 마지막 원판을 기둥 3에 옮긴다.
// k-1개의 워난을 기둥 3에 옮긴다.
// 원판 k+1때도 해결 가능하다.