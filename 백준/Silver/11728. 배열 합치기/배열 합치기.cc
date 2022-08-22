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

int n, m;
int arr1[1000000];
int arr2[1000000];
int sorted_arr[2000000];

void merge_sort() {
	int i = 0; int j = 0; int k = 0;
	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			sorted_arr[k] = arr1[i];
			i++;
		}
		else {
			sorted_arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	// 남은거 털어주기
	if (i < n) {
		for (int x = i; x < n; x++) {
			sorted_arr[k] = arr1[x];
			k++;
		}
	}
	if (j < m) {
		for (int x = j; x < m; x++) {
			sorted_arr[k] = arr2[x];
			k++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	merge_sort();
	for (int i = 0; i < n+m; i++)
		cout << sorted_arr[i] << ' ';
}