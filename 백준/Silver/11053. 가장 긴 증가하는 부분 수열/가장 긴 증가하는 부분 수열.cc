#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n, ans;
int arr[100005];
int d[100005]; // 해당 수로 끝나는 수열 중 가장 긴 수열을 저장하는 배열 
// 점화식 : 해당 수 이전에서 조건 만족하면서 가장 큰 값 + 1
// d[i] = max(d[i],d[j]+1)
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    fill(d + 1, d + n + 1, 1); // 하나만 있어도 하나의 길이를 가지므로
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) d[i] = max(d[i], d[j] + 1);
        }
    cout << *max_element(d + 1, d + n + 1);
}