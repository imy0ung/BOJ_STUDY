#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int M, N;
int arr1[100005];
int arr2[100005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr1[i];
	sort(arr1, arr1 + N);
	cin >> M;
	for (int i = 0; i < M; i++) cin >> arr2[i];

	for (int i = 0; i < M; i++) cout << binary_search(arr1,arr1+N,arr2[i]) << '\n';
}