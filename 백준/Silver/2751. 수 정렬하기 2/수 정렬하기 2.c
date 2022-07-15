#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable : 4996)
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

int q_sort(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}


int main(void)
{
	int N;
	scanf("%d", &N);
	
	int* a = calloc(N, sizeof(int));
	
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	qsort(a, N, sizeof(int), q_sort);

	for (int i = 0; i < N; i++)
		printf("%d\n", a[i]);
}