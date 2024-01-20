#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기

int n,v,cnt;
int arr[105];

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> v;
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) cnt++;
    }
    cout << cnt;
}