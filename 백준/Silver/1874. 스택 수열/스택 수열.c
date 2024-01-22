#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#pragma warning (disable : 4996)
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

typedef struct {
	int stk;
	int* ptr;
	int max;
}stack;

int init(stack* k, int max)
{
	k->ptr = calloc(max, sizeof(int));
	if (k->ptr == NULL) return -1;
	else {
		k->max = max;
		k->stk = 0;
	}
	return 0;
}

int push(stack* k, int x)
{
	if (k->max <= k->stk) return -1;
	k->ptr[k->stk++] = x;
	return 0;
}

int pop(stack* k)
{
	if (k->stk <= 0) return -1;
	k->stk--;
	k->ptr[k->stk] = 0;
	return 0;
}

int main()
{
	int n; scanf("%d", &n);
	int* arr = calloc(n, sizeof(int));
	char c[1000000];
	stack k;
	init(&k, n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int stk = 1;
	int flag = 0;
	int cc = 0;

	for (int i = 0; i < n; i++) {
		while (arr[i] >= stk) {
			push(&k, stk++);
			c[cc++] = '+';
		}
		if (arr[i] == k.ptr[k.stk - 1]){
			pop(&k);
			c[cc++] = '-';
		}
		else if (arr[i] != k.ptr[k.stk - 1]) {
			flag = 1; break;
		}
	}

	if (flag != 1) {
		for (int i = 0; i < cc; i++)
			printf("%c\n", c[i]);
	}
	else
		printf("NO");
}