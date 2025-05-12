#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100];

ll fibonacci(int n) {
    // base case
    if (n == 0 || n == 1) return n;

    // 이전에 계산한 값 재활용
    if (dp[n] != -1) return dp[n];

    // recursive case
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    fill(dp, dp + n + 1, -1);
    cout << fibonacci(n) << '\n';

    return 0;
}