#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#pragma warning (disable : 4996)

//boj 기준으로 1초에 1억번의 연산

using namespace std;

int arr[1000001];
// O(n^2)은 1억개를 초과하기 때문에, 시간복잡도 고려해야함

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N); // n * log n의 복잡도
	for (int i = 0; i < N; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		cout << arr[i] << '\n';
	}
}
