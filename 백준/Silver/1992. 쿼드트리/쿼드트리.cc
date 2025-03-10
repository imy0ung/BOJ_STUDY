#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// k step 때, 각 사분면의 색종이 개수를 알면 k+1일 때도 알 수 있다.
// k 일때 4분면의 출력값을 모아보면, k+1개의 출력값이 될 것

int N;
string board[70];

int check(int N, int r , int c) {
    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++)
            if (board[r][c] != board[i][j]) return 0;
    }

    return 1;
}

void func(int N, int r, int c) {
    if (check(N, r, c)) {
        cout << board[r][c];
        return;
    }
    int point = N / 2;
    cout << '(';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(point, r + point * i, c + point * j);
        }
    }
    cout << ')';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> board[i];
    
    func(N, 0, 0);
}