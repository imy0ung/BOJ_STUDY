#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int L, C;
char arr[50];
int idx[50];
int isused[50];

void func(int k) {
    if (k == L) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < L; i++) {
            if (arr[idx[i]] == 'a' || arr[idx[i]] == 'e' || arr[idx[i]] == 'i' ||
                arr[idx[i]] == 'o' || arr[idx[i]] == 'u') cnt1++;
            else cnt2++;
        }
        if (cnt1 >= 1 && cnt2 >= 2) {
            for (int i = 0; i < L; i++)
                cout << arr[idx[i]];
            cout << '\n';
        }
    }
    int st = 0;
    if (k != 0) st = idx[k-1] + 1;
    for (int i = st; i < C; i++) {
        if (!isused[i]) {
            idx[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> arr[i];
    sort(arr, arr + C);
    func(0);
}