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
        d[i] = max(0, d[i - 1]) + arr[i];
        // i번째 항으로 끝나는 연속합 중 최대라고 가정한다면,
        // 이전에 끝나는 수가 음수면, i부터 다시 시작해야한다.
        // 그러나 이전에 끝나는 수가 양수면 해당 수를 더하는게 최대값.
    }
    cout << *max_element(d + 1, d + n + 1);
}