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

int z(int N, int R, int C) {
	if (N == 0) return 0;
	int half = 1<<(N-1);
	
	if (R < half && C < half)
		return z(N - 1, R, C);
	if (R < half && C >= half)
		return half * half + z(N - 1, R, C - half);
	if (R >= half && C < half)
		return half * half * 2 + z(N - 1, R - half, C);
	if (R >= half && C >= half)
		return half * half * 3 + z(N - 1, R - half, C - half);
}
// 1번사각형 return z(N-1,R,C);
// 2번사각형 return half * half + z(N-1,R,C);
// 3번사각형 return half * half * 2 + z(N-1,R,C);
// 4번사각형 return half * half * 3 + z(N-1,R,C);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, R, C;
	cin >> N >> R >> C;
	cout << z(N, R, C);
}