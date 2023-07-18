#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		deque<int> dq;
		int rev = 0; // 회전 flag
		int sum = 0;
		int error = 0; // RR일 때, []가 나와야함
		string s; string arr;  int x;
		cin >> s; // 명령어
		cin >> x; // 숫자 입력
		cin >> arr; // arr 입력

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				sum = sum * 10 + (arr[i] - '0');
			}
			else if (arr[i] == ',' || (arr[i] == ']' && arr[i-1] != '[')) {
				dq.push_back(sum);
				sum = 0;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				if (rev == 0) rev = 1;
				else rev = 0;
			}
			else {
				if (dq.empty()) {
					cout << "error" << '\n';
					error = 1;
					break;
				}
				else if (rev == 1)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if (!error) {
			if (dq.empty())
				cout << '[' << ']'; // 빈 dq일때
			else if (rev == 1) {
				cout << '[';
				for (int i = dq.size() - 1; i > 0; i--) {
					cout << dq[i] << ',';
				}
				cout << dq[0] << ']';
			}
			else {
				cout << '[';
				for (int i = 0; i < dq.size() - 1; i++) {
					cout << dq[i] << ',';
				}
				cout << dq[dq.size() - 1] << ']';
			}
			cout << '\n';
		}
	}
}