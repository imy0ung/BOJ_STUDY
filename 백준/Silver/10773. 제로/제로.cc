#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,

stack<int> s;
int k;
int sum;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    while (k--) {
        int x; cin >> x;
        if (x == 0 && !s.empty()) s.pop();
        else s.push(x);
    }
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}