#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
int cnt;
int isused1[40];
int isused2[40];
int isused3[40];

void func(int cur) {
    if (cur == n) {
        cnt++;
    }
    for (int i = 0; i < n; i++) {
        if (!isused1[i] && !isused2[cur + i] && !isused3[cur - i + n - 1]) {
            isused1[i] = 1;
            isused2[cur + i] = 1;
            isused3[cur - i + n - 1] = 1;
            func(cur + 1);
            isused1[i] = 0;
            isused2[cur + i] = 0;
            isused3[cur - i + n - 1] = 0;
        }
    }
}

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}