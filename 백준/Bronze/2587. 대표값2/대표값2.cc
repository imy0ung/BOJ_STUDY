#include <iostream>	
#include <algorithm>

using namespace std;

int arr[10];
int avg;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		avg += arr[i];
	}
	sort(arr, arr + 5);
	cout << avg / 5 << '\n' << arr[2];
}