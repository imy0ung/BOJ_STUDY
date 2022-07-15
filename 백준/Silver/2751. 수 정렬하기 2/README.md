# [Silver V] 수 정렬하기 2 - 2751 

[문제 링크](https://www.acmicpc.net/problem/2751) 

### 성능 요약

메모리: 8928 KB, 시간: 484 ms

### 분류

정렬(sorting)

### 문제 설명

<p>N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.</p>

### 출력 

 <p>첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.</p>

### Comment

quick_sort 알고리즘으로 짤수도있지만, 퀵소트 알고리즘은 최적 시간 복잡도가 n * log n 이지, 최악의 복잡도는 n^2 이기 때문에 test case에서 틀렸었음.

밑 코드는 quick_sort 알고리즘으로 푼 코드

```
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#pragma warning (disable : 4996)

//boj 기준으로 1초에 1억번의 연산

using namespace std;

int arr[1000001];

void quick_sort(int arr[], int start, int end) {
	if (start >= end)
		return;// 하나만 존재하는 경우 

	int key = start;
	int i = start + 1; int j = end; int temp;

	while (i <= j) {
		while (i <= end && arr[key] >= arr[i]) {
			i++;
		} // 왼쪽으로 가면서, 큰걸 만날때 까지 증가
		while (j > start && arr[key] <= arr[j]) {
			j--;
		} // 오른쪽으로 가면서, 작은걸 만날때 까지 감소

		if (i > j) { // 엇갈린다면, pivot값을 바꿔줘야함.
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else { // 엇갈리지 않는다면, i의값과 j의값을 바꿔줌
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int main(void) {
	int number;
	cin >> number;
	
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}
	quick_sort(arr, 0, number - 1);
	for (int i = 0; i < number; i++) {
		cout << arr[i] << '\n';
	}
}
