#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
int sm, sd, lm, ld;
int t = 301;
int ans;
pair<int, int> day[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sm >> sd >> lm >> ld;
        day[i].first = sm * 100 + sd;
        day[i].second = lm * 100 + ld;
    }
    while (t < 1201) { // t는 시작일
        int cur = t; // 현재 일부터 최적의 선택을 찾기
        for (int i = 0; i < n; i++) {
            if (day[i].first <= cur && day[i].second > cur) {
                // 시작일이 현재일보다 작거나 같으면서도 현재일보다 끝나는일이 클 때
                // 한 바퀴 돌면서, 현재일에서 가장 많이 할 수 있는 일을 찾음
                t = max(t, day[i].second); // 다음 시작일 업데이트
            }
        }
        if (cur == t) { // 만약 현재일과 시작일이 같으면 종료
            cout << 0;
            return 0;
        }
        cur = t;
        ans++;
    }
    cout << ans;
}