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

deque<int> DQ;
int N;
int x;

int main(void) {
	cin >> N;
	while (N--) {
		string s; cin >> s;
		if (s == "push_front") {
			cin >> x;
			DQ.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			DQ.push_back(x);
		}
		else if (s == "pop_front") {
			if (DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		}
		else if (s == "size") {
			cout << DQ.size() << '\n';
		}
		else if (s == "empty") {
			cout << DQ.empty() << '\n';
		}
		else if (s == "front") {
			if (DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.front() << '\n';
			}
		}
		else if (s == "back") {
			if (DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.back() << '\n';
			}
		}
	}
}