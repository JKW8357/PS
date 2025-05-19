#include <bits/stdc++.h>
using namespace std;

int dp[100005][2];
int calc(int num1, char op, int num2) {
    if (op == '+') return num1 + num2;
    else if (op == '-') return num1 - num2;
    else if (op == '*') return num1 * num2;
    else return num1 / num2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    bool gameOver = false;
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        char op1, op2; int num1, num2;
        cin >> op1 >> num1 >> op2 >> num2;

        if (dp[i - 1][0] > 0) dp[i][0] = max(calc(dp[i - 1][0], op1, num1), calc(dp[i - 1][0], op2, num2));
        dp[i][1] = max({ dp[i - 1][0], calc(dp[i - 1][1], op1, num1), calc(dp[i - 1][1], op2, num2) });

        if (dp[i][0] <= 0 && dp[i][1] <= 0) gameOver = true;
    }

    int ans = max(dp[n][0], dp[n][1]);
    if (!gameOver) cout << ans << '\n';
    else cout << "ddong game\n";

    return 0;
}