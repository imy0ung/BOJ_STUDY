#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct {
	int* que;
	int front;
	int rear;
	int size;
	int num;
}yose;

int init(yose* y, int size) {
	y->que = calloc(size, sizeof(int));
	if (y->que == NULL) return -1;
	y->size = size;
	y->front = y->rear = y->num = 0;
	return 0;
}

int isempty(yose* y) {
	if (y->num == 0) return -1;
	return 0;
}

int isfull(yose* y) {
	if (y->num >= y->size) return -1;
	return 0;
}

int enque(yose* y, int x) {
	if (isfull(y) == -1)
		return -1;

	y->que[y->rear % y->size] = x;
	y->rear++;
	y->num++;
	return 0;
}

int deque(yose* y) {
	if (isempty(y) == -1) return -1;

	int x = y->que[y->front % y->size];
	y->front++;
	y->num--;
	return x;
}

int main()
{
	int n, m, x = 0;
	yose k;

	scanf("%d %d", &n, &m);
	init(&k, 5001);

	for (int i = 1; i <= n; i++) {
		enque(&k, i);
	}
	
	int tmp;

	printf("<");
	if (n != 1) {
		while (1) {
			for (int i = 0; i < m - 1; i++) {
				tmp = deque(&k);
				enque(&k, tmp);
			}
			printf("%d, ", deque(&k));
			
			if (k.num == 1) break;
		}
	}
	printf("%d", deque(&k));
	printf(">");

	return 0;
}