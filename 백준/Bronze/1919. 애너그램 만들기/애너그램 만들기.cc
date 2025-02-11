#include <iostream>	
#include <algorithm>
#define ll long long

using namespace std;
int arr1[26];
int arr2[26];
int ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s1, s2; 
	cin >> s1; cin >> s2;
	for (auto e : s1) arr1[e - 'a']++;
	for (auto e : s2) arr2[e - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (arr1[i] > arr2[i]) ans += arr1[i] - arr2[i];
		if (arr1[i] < arr2[i]) ans += arr2[i] - arr1[i];
	}
	cout << ans;
}