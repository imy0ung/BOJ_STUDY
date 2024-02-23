#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int d[1000005];
int pre[1000005];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << d[n] << '\n';
    int cur = n;
    while (true) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = pre[cur];
    }
}