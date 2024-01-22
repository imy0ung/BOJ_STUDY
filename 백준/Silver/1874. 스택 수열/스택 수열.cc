#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,

stack<int> s;
int n;
int cnt = 1;
string ans;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        int t; cin >> t;
        while (cnt <= t) {
            s.push(cnt++);
            ans += "+\n";
        }
        if (s.top() != t) {
            cout << "NO\n";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
}