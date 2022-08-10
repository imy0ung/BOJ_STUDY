#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
//binary search

int sort(const void* p, const void* q) {
	int num1 = *(int*)p;
	int num2 = *(int*)q;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	else
		return 0;
}

int bin(int arr[], int key, int n)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (arr[pc] == key)
			return 1;
		else if (arr[pc] < key)
			pl = pc + 1;
		else if (arr[pc] > key)
			pr = pc - 1;
	} while (pl <= pr);
	return 0;
}

int main()
{
	int arr1[100000] = { 0, };
	int arr2[100000] = { 0, };
	
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr1[i]);

	int M; scanf("%d", &M);
	
	for (int i = 0; i < M; i++)
		scanf("%d", &arr2[i]);

	qsort(arr1, N, sizeof(int), sort);

	for (int i = 0; i < M; i++) {
		printf("%d\n", bin(arr1, arr2[i], N));
	}
}