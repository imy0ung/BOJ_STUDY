#include <iostream>
#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;
using ll = long long;
// getline(cin,string s) => 공백을 포함한 문자 받기
// list- insert는 앞부분, iterator 햇갈리지말자,,
// deque vs vector, 메모리 연속성 차이, deque이 상위호환느낌

int n;
ll arr[55];
int isused[55]; // 사용확인배열
ll ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    // 매순간 괄호칠지, 치지 않을지 그리디적 관점으로 쭉가기
    // 양수는 오름차순인데,, 음수는 내림차순, 0처리는 음수에서
    for (int i = n - 1; i >= 1; i--) {
        // 양수는 1의 유무 때문에 괄호 칠지 안칠지 고려해야함
        if (!isused[i] && arr[i] > 0 && arr[i - 1] > 0) {
            if (arr[i] * arr[i - 1] > arr[i] + arr[i - 1]) 
                ans += arr[i] * arr[i - 1];
            else ans += arr[i] + arr[i - 1];
            isused[i] = 1;
            isused[i - 1] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (!isused[i] && arr[i] <= 0 && arr[i + 1] <= 0) {
            // 음수는 무조건 곱해주는게 유리
            ans += arr[i] * arr[i + 1];
            isused[i] = 1;
            isused[i + 1] = 1;
        }
    }
    // 남은 수는 그냥 더해주기 (홀수 개수 일때)
    for (int i = 0; i < n; i++) {
        if (!isused[i]) ans += arr[i];
    }
    cout << ans;
}