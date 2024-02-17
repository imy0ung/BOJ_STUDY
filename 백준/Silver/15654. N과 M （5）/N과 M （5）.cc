#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n, m;
int isused[10000];
int arr[10];
int inp[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[inp[i]]) {
            arr[k] = inp[i];
            isused[inp[i]] = 1;
            func(k + 1);
            isused[inp[i]] = 0;
        }
    }
}

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> inp[i];
    sort(inp, inp + n);
    func(0);
}