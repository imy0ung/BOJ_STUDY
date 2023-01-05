#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <list>

using namespace std;

int arr[26];
// iterator = container 내의 포인터
// refernce = 일종의 별명, 변수를 통해 같은 공간을 써서 메모리가 차지 x
// range - based for loop

int n;
string s;
list<char> x;
list<char>::iterator it;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (auto e : s)
		x.push_back(e);

	it = x.end();
	cin >> n;

	while (n--) {
		char command;
		cin >> command;

		if (command == 'L') {
			if (it != x.begin())
				it--;
		}
		else if (command == 'D') {
			if (it != x.end()) {
				it++;
			}
		}
		else if (command == 'B') {
			if (it != x.begin()) {
				it--;
				it = x.erase(it);
			}
		}
		else if (command == 'P') {
			char c; cin >> c;
			x.insert(it, c);
		}
	}
	for (auto e : x)
		cout << e;
}
