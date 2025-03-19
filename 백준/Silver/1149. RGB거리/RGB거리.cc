#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int h[1005][3];
int d[1005][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i][0] >> h[i][1] >> h[i][2];
    d[1][0] = h[1][0]; d[1][1] = h[1][1]; d[1][2] = h[1][2];

    for (int i = 1; i <= n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + h[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + h[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + h[i][2];
    }

    cout << *min_element(d[n], d[n] + 3);
}