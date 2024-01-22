#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    stack<char> s;
    int ans = 0;
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') s.push(str[i]);
        else if (str[i] == ')') {
            if (str[i-1] == '(') {
                s.pop();
                ans += s.size();
            }
            else {
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;
}