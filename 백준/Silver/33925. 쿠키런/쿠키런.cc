#include <bits/stdc++.h>
using namespace std;

string board[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, j, s, h, k;
    cin >> n >> j >> s >> h >> k;
    for (int i = 0; i < 3; i++) cin >> board[i];

    int low = 0, high = 0, top = 0;
    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'v') top++;
        else if (board[1][i] == '^') high++;
        else if (board[2][i] == '^') low++;
    }

    int hitCnt = 0;
    hitCnt += max(top - s, 0);
    hitCnt += max(low - j, 0);
    j = max(j - low, 0);
    hitCnt += max((2 * high - j + 1) / 2, 0);

    int ans = h - k * hitCnt;
    cout << (ans > 0 ? ans : -1) << '\n';

    return 0;
}