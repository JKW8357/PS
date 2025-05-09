#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll board[2005][2005];
ll sum[2005][2005];
ll bomb[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            board[i][j] *= -1;
        }
    }


    for (int i = 1; i <= n - m + 1; i++) {
        for (int j = 1; j <= n - m + 1; j++) {
            bomb[i + m / 2][j + m / 2] = board[i][j] - (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
            if (i >= m) bomb[i + m / 2][j + m / 2] += sum[i - m][j];
            if (j >= m) bomb[i + m / 2][j + m / 2] += sum[i][j - m];
            if (i >= m && j >= m) bomb[i + m / 2][j + m / 2] -= sum[i - m][j - m];
            sum[i][j] = bomb[i + m / 2][j + m / 2] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << bomb[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}