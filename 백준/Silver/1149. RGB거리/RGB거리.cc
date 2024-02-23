#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
int R[1005];
int G[1005];
int B[1005];
int d[1005][4];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> R[i] >> G[i] >> B[i];
   
    d[1][1] = R[1]; d[1][2] = G[1]; d[1][3] = B[1];

    for (int i = 2; i <= n; i++) {
        d[i][1] = min(d[i - 1][2], d[i - 1][3]) + R[i];
        d[i][2] = min(d[i - 1][1], d[i - 1][3]) + G[i];
        d[i][3] = min(d[i - 1][1], d[i - 1][2]) + B[i];
    }
    cout << min({ d[n][1], d[n][2] ,d[n][3] });
}