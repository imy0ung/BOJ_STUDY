#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// k step 때, 각 사분면의 색종이 개수를 알면 k+1일 때도 알 수 있다.

int paper[2200][2200];
int ans[3];
int n;

int check(int k, int r, int c) {
    for (int i = r; i < r + k; i++) {
        for (int j = c; j < c + k; j++) {
            if (paper[r][c] != paper[i][j]) 
                return 0;
        }
    }
    return 1;
}

void func(int k, int r, int c) {
    if (check(k,r,c)) {
        ans[paper[r][c] + 1]++;
        return;
    }

    int tmp = k / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func(tmp, r + tmp * i, c + tmp * j); // 초기 r과 c가 있어야함
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    func(n, 0, 0);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
}