#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기

string s;
int m;
list<char> l;

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> m;
    for (auto e : s) {
        l.push_back(e);
    }

    auto t = l.end();

    while (m--) {
        char c;
        cin >> c;
        if (c == 'P') {
            char x;
            cin >> x;
            l.insert(t, x);
        }
        if (c == 'L') {
            if (t != l.begin()) t--;
        }
        if (c == 'D') {
            if (t != l.end()) t++;
        }
        if (c == 'B') {
            if (t != l.begin()) {
                t--;
                t = l.erase(t);
            }
        }
    }
    for (auto e : l) cout << e;
}