#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int main(void) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0; // 덧셈을 해주는 변수
    int mul = 1; // 분배법칙의 괄호 밖 변수
    string str; cin >> str;
    stack<char> s; // 괄호 유효성 검사를 위한 stack
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            mul *= 2;
            s.push('(');
        }
        else if (str[i] == '[') {
            mul *= 3;
            s.push('[');
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            else {
                if (str[i - 1] == '(') {
                    sum += mul;
                }
            }
            mul /= 2;
            s.pop();
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top()!= '[') {
                cout << 0;
                return 0;
            }
            else {
                if (str[i - 1] == '[') {
                    sum += mul;
                }
            }
            mul /= 3;
            s.pop();
        }
    }
    if (s.empty()) cout << sum;
    else cout << 0;
    
    return 0;
}