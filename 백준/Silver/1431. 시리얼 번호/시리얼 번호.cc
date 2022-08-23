#include <iostream>
#include <algorithm>
#include <vector> // pair library
#pragma warning(disable:4996)

// 1181번 (문자열 정렬)

using namespace std;
int n;

int getSum(string a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string &a, string &b) {
	int sum1 = 0, sum2 = 0;

	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	else {
		int asum = getSum(a);
		int bsum = getSum(b);

		if (asum != bsum) {
			return asum < bsum;
		}
		else
			return a < b;
	}
}

int main(void) {
	vector<string> v;
	string k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}