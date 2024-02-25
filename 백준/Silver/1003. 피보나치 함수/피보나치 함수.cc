#include <iostream>
#include <algorithm>
#include <vector> // pair library
#include <stack>
#include <queue>
#include <cmath>
#pragma warning(disable:4996)

using namespace std; //dynamic program

int d[100];

int fibo(int n) {
	if (n == 0) return 0; // 재귀함수 종료조건
	if (n <= 1)  return 1;

	if (d[n] != 0) return d[n];
	return d[n] = fibo(n - 1) + fibo(n - 2);
}
int main(void) {
	int t; scanf("%d", &t);
	int a;

	for (int i = 0; i < t; i++) {
		scanf("%d", &a);
		if (a == 0) printf("1 0\n");
		else 
			printf("%d %d\n", fibo(a - 1), fibo(a));
	}
}