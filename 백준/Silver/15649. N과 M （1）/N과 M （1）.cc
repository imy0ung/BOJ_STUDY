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

int n, m; // 입력으로 주어진 값
int arr[10]; // 수열에 담을 배율
bool isused[10]; // 특정수가 쓰였는가

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	} // m개가 택해서 종료 조건
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) { // 아직쓰이지않았다면
			arr[k] = i;
			isused[i] = 1; // 사용함으로 선언하고 
			func(k + 1); // 다음행으로 넘겨줌
			isused[i] = 0; // 사용되지 않음
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}