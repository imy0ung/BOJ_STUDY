#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int d[100000];

int solution(int n) {
    int answer = 0;
    d[0] = 0; d[1] = 1; d[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2])%1234567;
    }
    return d[n];
}