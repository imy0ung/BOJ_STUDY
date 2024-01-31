#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

string board[200];
int n;

bool check(int n, int r, int c) {
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (board[r][c] != board[i][j])
                return false;
        }
    }
    return true;
}

void func(int n, int r, int c) {
    // base-condition : 같은 종류일 때 종료
    if (check(n, r, c)) {
        cout << board[r][c];
        int half = 1 << (n - 1);
        return;
    }
    cout << '(';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(n / 2, r + i * n / 2, c + j * n / 2);
        }
    }
    cout << ')';
    // 괄호 자체가 압축을 의미하는 건데 왜이리 돌아갔나..ㅜ
}

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    func(n, 0, 0);
}