#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int cnt;
int isused[25];

void func(vector<int> numbers, int k, int s, int target) {
    if (k == numbers.size()) {
        if (s == target) cnt++;
        return;
    }
    func(numbers, k + 1, s + numbers[k], target);
    func(numbers, k + 1, s - numbers[k], target);
}

int solution(vector<int> numbers, int target) {
    func(numbers, 0, 0, target);
    int answer = cnt;
    return answer;
}