#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
int arr[100005];
int d[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    d[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        int k = 0;
        int max_d = INT_MIN;
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < arr[i] && d[j] > max_d) {
                max_d = d[j];
                k = j;
            }
        }
        d[i] = max(d[k], 0) + arr[i];
    }
    cout << *max_element(d + 1, d + n + 1);
}