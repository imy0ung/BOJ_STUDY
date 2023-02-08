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

int N, S;
int cnt;
int arr[30];

void func(int k, int tot) {
	if (k == N) {
		if (tot == S) cnt++;
		return;
	}
	func(k + 1, tot); // 왼쪽 : 추가안한거
	func(k + 1, tot + arr[k]); // 오른쪽 : 추가한거
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;
}