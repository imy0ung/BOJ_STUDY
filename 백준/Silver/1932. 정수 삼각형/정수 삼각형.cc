#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
int height = 1;
int t[505][505];
int d[505][505];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> t[i][j];
        }
    }
    d[1][1] = t[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
        }
    }
    cout << *max_element(d[n] + 1, d[n] + n + 1);
}