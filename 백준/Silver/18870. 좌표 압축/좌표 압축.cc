#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	int number;
	cin >> number;
	vector<int> v1(number);

	for (int i = 0; i < number; i++) {
		cin >> v1[i];
	}

	vector<int> v2(v1);
	sort(v2.begin(), v2.end());

	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	// unique 함수는 연속으로 중복되는 원소를 vector 제일 뒷부분으로 보낸다.
	// 반환은 제일 뒷부분으로 보낸 숫자의 첫번째 iterator (주소)

	for (int i = 0; i < number; i++) {
		v1[i] = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
		cout << v1[i] << ' ';
	} // lower_bound는 iterator를 반환하므로, 순서를 알고싶으면 빼준다.
}