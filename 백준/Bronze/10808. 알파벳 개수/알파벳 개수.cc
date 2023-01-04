#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<string>

using namespace std;

int arr[26];
// iterator = container 내의 포인터
// refernce = 일종의 별명, 변수를 통해 같은 공간을 써서 메모리가 차지 x

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; 
	cin >> s;
	for (char e : s)
		arr[e - 'a']++;
	for (int e : arr)
		cout << e << ' ';
}