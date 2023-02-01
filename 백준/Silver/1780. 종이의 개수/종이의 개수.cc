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

int arr[2200][2200];
int cnt[3];

bool check(int N, int r, int c) {
	for (int i = r; i < r + N; i++) {
		for (int j = c; j < c + N; j++) {
			if (arr[r][c] != arr[i][j])
				return false;
		}
	}
	return true;
}
void paper(int N, int r, int c) {
	if (check(N, r, c)) {
		cnt[arr[r][c] + 1] += 1;
		return;
	}
	int delta = N / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			paper(delta, r + delta * i, c + delta * j);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	paper(N, 0, 0);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}

// basecondition이 있는가? N이 1이면 종료 한다. -> 실력자는 같은종이면 종료한다로 함 
// paper(k)를 9조각의 사각형에 대해 재귀를 호출한다?
// 재귀가 9번인데 터지지않을까