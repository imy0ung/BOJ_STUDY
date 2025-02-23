#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            q.push(x);
        }
        if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        if (s == "size") {
            cout << q.size() << '\n';
        }
        if (s == "empty") {
            if (!q.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        if (s == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        if (s == "back") {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}