#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#pragma warning (disable : 4996)
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

typedef struct {
	int stk;
	char* ptr;
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

int peak(stack* k)
{
	if (k->stk <= 0) return -1;
	return k->ptr[k->stk - 1];
}

int empty(stack* k)
{
	if (k->stk > 0) return 1;
	else
		return 0;
}

int main()
{	
	char arr[101];
	int len = 0;
	int flag = 0;
	stack k;

	while (1)
	{
		gets(arr);
		len = strlen(arr);
		init(&k, 101);
		flag = 0;

		if (strcmp(arr, ".") == 0) break;

		for (int i = 0; i < len; i++)
		{
			if (arr[i] == '(' || arr[i] == '[') push(&k, arr[i]);

			if (arr[i] == ')') {
				if (empty(&k) == 1 && peak(&k) == '(') pop(&k);
				else {
					flag = 1;
					printf("no\n");
					break;
				}
			}

			if (arr[i] == ']') {
				if (empty(&k) == 1 && peak(&k) == '[') pop(&k);
				else {
					flag = 1;
					printf("no\n");
					break;
				}
			}
		}

		if (flag != 1) {
			if (k.stk == 0) printf("yes\n");
			else printf("no\n");
		}
	}
}