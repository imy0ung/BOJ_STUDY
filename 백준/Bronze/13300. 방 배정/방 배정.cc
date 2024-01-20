#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기

int n, k, ans;
int info[7][7];

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int s, y;
        cin >> s >> y;
        info[y-1][s]++;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            if (info[i][j] / k == 0 && info[i][j] != 0) {
                ans += 1;
            }
            if (info[i][j] / k != 0) {
                ans += info[i][j] / k;
                if (info[i][j] % k != 0)
                    ans += 1;
            }
        }
    }
    cout << ans;
}