#include <iostream>	
#include <algorithm>

using namespace std;

int s;
int arr[15];
int carr[105];

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		carr[arr[i]] = 1;
		s += arr[i];
	}
	sort(arr, arr + 9);
	int chk = s - 100;
	for (int i = 0; i < 9; i++) {
		if (carr[chk - arr[i]] == 1) {
			carr[arr[i]] = 0; 
			carr[chk - arr[i]] = 0;
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (carr[arr[i]] == 0) continue;
		cout << arr[i] << '\n';
	}
}