#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

string s;
int number;
int minusflag = 1;
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || s[i] == NULL) {
            ans += number * minusflag;
            if (s[i] == '-') {
                minusflag = -1;
            }
            number = 0;
        }
        else {
            number = number * 10 + (s[i] - '0');
        }
    }
    cout << ans;
}