#include <iostream>	
#include <algorithm>
#define ll long long

using namespace std;

int card[10];

int main() {
	int N; cin >> N;
	
	while (N != 0) {
		int k = N % 10;
		N /= 10;

		if (card[k] == 0) {
			if (k == 6 && card[9] > 0) card[9]--;

			else if (k == 9 && card[6] > 0) card[6]--;

			else {
				for (int i = 0; i <= 9; i++) {
					if (i == k) continue;
					card[i]++;
				}
			}
		}
		else card[k]--;
	}
	cout << *max_element(card, card + 10);
}