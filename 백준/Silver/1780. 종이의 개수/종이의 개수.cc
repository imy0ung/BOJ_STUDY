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
int cnt0, cnt1, cnt2;

void paper(int N, int r, int c) {
	int flag = 0; int st = arr[r][c];
	if (N == 1) {
		if (st == 0) cnt0++;
		if (st == 1) cnt1++;
		if (st == -1) cnt2++;
		return;
	} // base condition
	for (int i = r; i < r + N; i++) {
		for (int j = c; j < c + N; j++) {
			if (st != arr[i][j]) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) { // 같은 종이가 아니면
		paper(N / 3, r, c);
		paper(N / 3, r + (N / 3), c);
		paper(N / 3, r + 2 * (N / 3), c);

		paper(N / 3, r, c + (N / 3));
		paper(N / 3, r + (N / 3), c + (N / 3));
		paper(N / 3, r + 2 * (N / 3), c + (N / 3));

		paper(N / 3, r, c + 2 * (N / 3));
		paper(N / 3, r + (N / 3), c + 2 * (N / 3));
		paper(N / 3, r + 2 * (N / 3), c + 2 * (N / 3));
	}
	else { // 같은 종이 일 경우,
		if (st == 0) cnt0++;
		if (st == 1) cnt1++;
		if (st == -1) cnt2++;
	}
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
	cout << cnt2 << '\n' << cnt0 << '\n' << cnt1;
}

// basecondition이 있는가? N이 1이면 종료 한다.
// paper(k)를 9조각의 사각형에 대해 재귀를 호출한다?
// 재귀가 9번인데 터지지않을까