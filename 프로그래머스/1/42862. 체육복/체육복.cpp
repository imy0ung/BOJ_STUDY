#include <bits/stdc++.h>

using namespace std;

int ischeck[35];
int cnt = 0;

int FD(int n, vector<int> lost, vector<int> reserve) {
    fill(ischeck+1, ischeck+n+1, 1);
    for (int i = 0; i < reserve.size(); i++) {
        ischeck[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        ischeck[lost[i]]--;
    }
    
    for (int i = 1; i <= n; i++) {
        if (ischeck[i] == 0) {
            if (ischeck[i-1] >= 2) {
                ischeck[i-1]--;
                ischeck[i]++;
            }
            else if (ischeck[i+1] >= 2) {
                ischeck[i+1]--;
                ischeck[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ischeck[i] >= 1) cnt++;
    }
    
    return cnt;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = FD(n,lost,reserve);
    return answer;
}