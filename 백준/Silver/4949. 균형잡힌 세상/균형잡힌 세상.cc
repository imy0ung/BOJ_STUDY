#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <list>

using namespace std;

// iterator = container 내의 포인터
// refernce = 일종의 별명, 변수를 통해 같은 공간을 써서 메모리가 차지 x
// range - based for loop
// getlin(cin,s) -> 공백을 포함해서 받음


int main(void) {
	while (1) {
		string a;
		getline(cin, a);
		if (a == ".") break;
		stack<char> s;
		bool isValid = true;
		for (auto c : a) {
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					isValid = false;
					break; // empty 안넣으면 컴파일에러가 남
				} // 같은 괄호인가 1
				s.pop(); // 조건 부합시 pop
			}
			else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					isValid = false;
					break;
				} // 같은 괄호인가 2
				s.pop(); // 조건 부합시 pop
			}
		}
		if (!s.empty()) isValid = false; // 스택이 안비어있으면 false
		if (isValid) cout << "yes\n";
		else cout << "no\n";
	}
}