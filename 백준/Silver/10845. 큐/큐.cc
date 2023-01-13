#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

// iterator = container's pointer
// reference = 일종의 별명, 같은 공간, 메모리 차지 x
// range-based for loop // for (auto e : s)

using namespace std;

queue<int> Q;
int N, x;
string s;

int main(void) {
	cin >> N;
	while (N--) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			Q.push(x);
		}
		else if (s == "pop") {
			if (Q.empty()) cout << "-1\n";
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (s == "size") {
			cout << Q.size() << '\n';
		}
		else if (s == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (s == "front") {
			if (Q.empty()) cout << "-1\n";
			else cout << Q.front() << '\n';
		}
		else if (s == "back") {
			if (Q.empty()) cout << "-1\n";
			else cout << Q.back() << '\n';
		}
	}
}