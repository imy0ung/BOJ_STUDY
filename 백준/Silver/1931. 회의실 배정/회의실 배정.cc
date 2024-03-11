#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n, ans = 1;
pair<int, int> t[100005];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t, t + n,compare);
    int cur = t[0].second;
    for (int i = 1; i < n; i++) {
        if (t[i].first >= cur) {
            cur = t[i].second; ans++;
        }
    }
    cout << ans;
}