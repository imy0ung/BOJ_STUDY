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
int arr[10]; // 수열을 담는 배열
bool isused[10]; // 특정 수가 쓰였는지

void func(int k) { //func(k)는 k개까지의 수를 선택한 상황에서 arr[k]를 정하는 함수
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	} // base condition, m개를 택했으니 종료
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i; // k번째에 i 집어넣고
			isused[i] = 1; // 방문처리
			func(k + 1); // k+1번째 일때도 실행
			isused[i] = 0; // 다시 방문처리해제
		}
	}
}

int main(void) { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}
// 백트래킹 : 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘