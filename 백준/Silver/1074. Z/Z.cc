#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

// iterator = container's pointer
// reference = 일종의 별명, 같은 공간, 메모리 차지 x
// range-based for loop // for (auto e : s)

using namespace std;

int z(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half) // 첫번째 사각형
		return z(n - 1, r, c);
	if (r < half && c >= half) // 두번째 사각형
		return (half * half) + z(n - 1, r, c - half);
	if (r >= half && c < half) // 세번째 사각형
		return (half * half * 2) + z(n - 1, r - half, c);
	if (r >= half && c >= half) // 네번째 사각형
		return (half * half * 3) + z(n - 1, r - half, c - half);
}

int main(void) {
	int n, r, c;
	cin >> n >> r >> c;
	cout << z(n, r, c);
}