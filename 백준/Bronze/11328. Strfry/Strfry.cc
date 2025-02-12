#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    while (N--) {
        string s1, s2;
        int arr1[26]; int arr2[26];
        int flag = 0;
        fill(arr1, arr1 + 26, 0);
        fill(arr2, arr2 + 26, 0);
        cin >> s1 >> s2;

        for (auto e : s1) arr1[e - 'a']++;
        for (auto e : s2) arr2[e - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                cout << "Impossible\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0) cout << "Possible\n";
    }
    return 0;
}