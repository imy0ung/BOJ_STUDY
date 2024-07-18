#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stk;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push('(');
        else if (s[i] == ')') { 
            if (!stk.empty() && stk.top() == '(') stk.pop();
            else stk.push(')');
        }
    }
    
    answer = stk.empty();

    return answer;
}