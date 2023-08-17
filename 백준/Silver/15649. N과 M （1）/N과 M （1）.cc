#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int k) { //k번째까지
	if (k == m) { //모든 트리를 탐색했다면 출력
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return; // 탐색 끝났으면 종료
	}
	for (int i = 1; i <= n; i++) { // n번째 수까지 순회하면서
		if (!isused[i]) { // 만약 사용하지 않았다면
			arr[k] = i; // 삽입
			isused[i] = 1; // 사용처리해주고
			func(k + 1); // 더 깊숙히 탑색
			isused[i] = 0; // func가 끝나면 순회 종료니 다시, 0으로해줌
		}
	}
}

int main(void) {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}