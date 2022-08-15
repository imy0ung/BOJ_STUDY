#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)
#define swap(type , a, b) do {type t; t = a; a = b; b = a;}while(0) 

void recur(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) printf(" ");
	else {
		if (n / 3 == 0) printf("*");
		else recur(i, j, n / 3);
	}
}

int main(void) {
	int n; scanf("%d", &n);
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			recur(i, j, n);
		}
		printf("\n");
	}
}