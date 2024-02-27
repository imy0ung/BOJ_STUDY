#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n, ans;
ll arr[100005];
ll d[100005];
ll c = 1;
// 점화식 : d[i] = d[i-1] + d[c];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
    for (int i = 6; i <= 100; i++) {
        d[i] = d[i - 1] + d[c];
        c++;
    }
    while (n--) {
        int x; cin >> x;
        cout << d[x] << '\n';
    }
}