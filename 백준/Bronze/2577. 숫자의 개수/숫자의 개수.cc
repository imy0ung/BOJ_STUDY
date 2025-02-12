#include <iostream>	
#include <algorithm>
#define ll long long

using namespace std;


int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int x = A * B * C;
	int arr[10] = {};

	while (x != 0) {
		int k = x % 10;
		x /= 10;
		arr[k]++;
	}
	for (auto e : arr) cout << e << '\n';
}