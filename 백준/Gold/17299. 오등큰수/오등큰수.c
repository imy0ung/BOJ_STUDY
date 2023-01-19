#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct {
	int* stack;
	int num;
	int size;
}odong;

int init(odong* o, int size)
{
	o->stack = calloc(size, sizeof(int));
	if (o->stack == NULL) return -1;
	o->num = 0;
	o->size = size;
	return 0;
}

int push(odong* o, int x)
{
	if (o->num >= o->size) return -1;
	o->stack[o->num++] = x;
	return 0;
}

int pop(odong* o)
{
	if (o->num <= 0) return -1;
	int x = o->stack[o->num - 1];
	o->num--;
	return x;
}

int empty(odong* o)
{
	if (o->num == 0) return 1;
	else return 0;
}

int top(odong* o)
{
	if (o->num <= 0) return -1;
	return o->stack[o->num - 1];
}

int cnt[1000001] = { 0, };
int arr[1000001] = { 0, };
int ans[1000001] = { 0, };
int main()
{
	int n; scanf("%d", &n);
	odong o;
	init(&o, n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}

	int knt = 0;

	for (int i = n - 1; i >= 0; i--) {
		while (empty(&o) != 1) {
			if (cnt[arr[i]] >= cnt[top(&o)])
				pop(&o);
			else break;
		}
		if (empty(&o) == 1)
			ans[knt++] = -1;
		else
			ans[knt++] = top(&o);

		push(&o, arr[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
}